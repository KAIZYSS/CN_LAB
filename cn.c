// #include <stdio.h>

// int main(){
//     int count=0;
//     char data[20];
//     char choice;

//     printf("Enter Binary data: ");
//     scanf("%s",data);

//     printf("e for even and o for odd: ");
//     scanf(" %c",&choice);

//     for(int i=0; data[i]!='\0'; i++){
//         if(data[i]=='1'){
//             count++;
//         }
//     }

//     if(choice=='e' && count%2==0){
//         printf("Even Parity");
//     }
//     else if(choice=='o' && count%2!=0){
//         printf("Odd Parity");
//     }
//     else{
//         printf("Parity doesn't match");
//     }

//     return 0;
// }
// #include <stdio.h>
// int main() {
//     int rows, cols;
//     int data[10][10];

//     printf("Enter rows and columns: ");
//     scanf("%d %d", &rows, &cols);

//     printf("Enter data:\n");
//     for(int i=0;i<rows;i++)
//         for(int j=0;j<cols;j++)
//             scanf("%d",&data[i][j]);

//     printf("LRC: ");
//     for(int j=0;j<cols;j++) {
//         int count = 0;
//         for(int i=0;i<rows;i++) {
//             if(data[i][j] == 1)
//                 count++;
//         }
//         printf("%d ", count % 2);
//     }

//     return 0;
// }
#include <stdio.h>
// int main() {
//     int n, m;
//     int data[10][10];

//     printf("Enter rows and bits: ");
//     scanf("%d %d", &n, &m);

//     printf("Enter data:\n");
//     for(int i=0;i<n;i++) {
//         int count = 0;
//         for(int j=0;j<m;j++) {
//             scanf("%d",&data[i][j]);
//             if(data[i][j] == 1)
//                 count++;
//         }
//         printf("Parity for row %d = %d\n", i+1, count % 2);
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char data[50], key[20], temp[50];

//     printf("Enter data: ");
//     scanf("%s", data);

//     printf("Enter key: ");
//     scanf("%s", key);

//     strcpy(temp, data);

//     for(int i=0;i<strlen(key)-1;i++)
//         strcat(temp,"0");

//     for(int i=0;i<=strlen(temp)-strlen(key);i++){
//         if(temp[i]=='1'){
//             for(int j=0;j<strlen(key);j++){
//                 temp[i+j] = (temp[i+j]==key[j]) ? '0':'1';
//             }
//         }
//     }

//     printf("CRC: %s\n", temp + strlen(data));

//     return 0;
// }

// #include <stdio.h>
// int main(){
//     int n, data[20],sum=0;

//     printf("eneter no of elements:");
//     scanf("%d",&n);
//     printf("enter data:");
//     for(int i=0;i<n;i++){  
//         scanf("%d",&data[i]);
//         sum+=data[i];
//     }
//     int checksum = ~sum;
//     printf("Check sum=%d", checksum);
//     return 0;
// }
