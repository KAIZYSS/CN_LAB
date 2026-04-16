🔴 DISTANCE VECTOR ROUTING
PROCEDURE
Start the program.
Read the number of nodes.
Read the cost (adjacency) matrix.
Initialize distance matrix with given costs.
Apply Distance Vector (Bellman-Ford) update using 3 nested loops.
Update distance if a shorter path is found.
Display the shortest distance matrix.
Stop the program.
PROGRAM
#include <stdio.h>

#define INF 999

int main() {
    int n;
    int cost[10][10], dist[10][10];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &cost[i][j]);
            dist[i][j] = cost[i][j];
        }
    }

    // Distance Vector Algorithm
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nShortest Distance Matrix:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}

🔴 TCP DIJKSTRA
PROCEDURE
Start the program.
Create TCP socket using socket().
Bind server using bind().
Listen using listen() and accept client using accept().
Client sends number of nodes and adjacency matrix.
Server receives data using recv().
Apply Dijkstra’s algorithm.
Send shortest distances back using send().
Close sockets and stop.
SERVER CODE
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define INF 999

int main() {
    int s, c, n, graph[10][10];
    struct sockaddr_in server;

    s = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(s, (struct sockaddr*)&server, sizeof(server));
    listen(s, 3);

    c = accept(s, NULL, NULL);

    recv(c, &n, sizeof(n), 0);
    recv(c, graph, sizeof(graph), 0);

    int dist[10], visited[10] = {0};

    for(int i=0;i<n;i++) dist[i] = INF;
    dist[0] = 0;

    for(int i=0;i<n-1;i++){
        int min = INF, u;

        for(int j=0;j<n;j++)
            if(!visited[j] && dist[j] < min){
                min = dist[j];
                u = j;
            }

        visited[u] = 1;

        for(int v=0;v<n;v++)
            if(!visited[v] && graph[u][v] && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    send(c, dist, sizeof(dist), 0);

    close(c);
    close(s);
    return 0;
}
CLIENT CODE
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock, n, graph[10][10], dist[10];
    struct sockaddr_in server;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr*)&server, sizeof(server));

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &graph[i][j]);

    send(sock, &n, sizeof(n), 0);
    send(sock, graph, sizeof(graph), 0);

    recv(sock, dist, sizeof(dist), 0);

    printf("Shortest distances:\n");
    for(int i=0;i<n;i++)
        printf("%d ", dist[i]);

    close(sock);
    return 0;
}
UDP DIJKSTRA
PROCEDURE
Start the program.
Create UDP socket using socket().
Bind server using bind().
Client sends data using sendto().
Server receives data using recvfrom().
Apply Dijkstra’s algorithm.
Send result using sendto().
Client receives using recvfrom().
Stop the program.
SERVER CODE
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define INF 999

int main() {
    int sock, n, graph[10][10];
    struct sockaddr_in server, client;
    socklen_t len;

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (struct sockaddr*)&server, sizeof(server));

    len = sizeof(client);

    recvfrom(sock, &n, sizeof(n), 0, (struct sockaddr*)&client, &len);
    recvfrom(sock, graph, sizeof(graph), 0, (struct sockaddr*)&client, &len);

    int dist[10], visited[10] = {0};

    for(int i=0;i<n;i++) dist[i] = INF;
    dist[0] = 0;

    for(int i=0;i<n-1;i++){
        int min = INF, u;

        for(int j=0;j<n;j++)
            if(!visited[j] && dist[j] < min){
                min = dist[j];
                u = j;
            }

        visited[u] = 1;

        for(int v=0;v<n;v++)
            if(!visited[v] && graph[u][v] && dist[u]+graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    sendto(sock, dist, sizeof(dist), 0, (struct sockaddr*)&client, len);

    close(sock);
    return 0;
}
CLIENT CODE
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock, n, graph[10][10], dist[10];
    struct sockaddr_in server;
    socklen_t len;

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    len = sizeof(server);

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &graph[i][j]);

    sendto(sock, &n, sizeof(n), 0, (struct sockaddr*)&server, len);
    sendto(sock, graph, sizeof(graph), 0, (struct sockaddr*)&server, len);

    recvfrom(sock, dist, sizeof(dist), 0, NULL, NULL);

    printf("Shortest distances:\n");
    for(int i=0;i<n;i++)
        printf("%d ", dist[i]);

    close(sock);
    return 0;
}
