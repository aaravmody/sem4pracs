#include <stdio.h>
#include <stdlib.h>

//fcfs
// void main()
// {
//     int arr[10],discno,head,totalmovement=0;
//     printf("Enter no of disk: ");
//     scanf("%d",&discno);

//     printf("Enter all discs: ");
//     for(int i=0;i<discno;i++)
//     {
//         scanf("%d",&arr[i]);
//     }

//     printf("Head ");
//     scanf("%d",&head);

//     for(int i=0;i<discno;i++)
//     {
//         totalmovement+=abs(head-arr[i]);
//         head=arr[i];
//     }

//     printf("total movement %d",totalmovement);
// }

//SCAN
// void main()
// {
//     int arr[10],discno,head,totalmovement=0,max;
//     printf("Enter no of disk: ");
//     scanf("%d",&discno);

//     printf("Enter all discs: ");
//     for(int i=0;i<discno;i++)
//     {
//         scanf("%d",&arr[i]);
//     }

//     printf("Head ");
//     scanf("%d",&head);

//     printf("Max ");
//     scanf("%d",&max);

//     for(int i=0;i<discno;i++)
//     {
//         for(int j=0;j<discno-i-1;j++)
//         {
//             if(arr[j]>arr[j+1])
//             {
//                 int temp=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=temp;
//             }
//         }
//     }

// totalmovement=(abs(max-head)+abs(max-arr[0]));

//     printf("total movement %d",totalmovement);
// }

