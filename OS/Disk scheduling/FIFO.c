#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n,head,totalmovement;
    int disk[10];
    printf("Enter number of disk tracks: ");
    scanf("%d",&n);

    printf("Enter the disk tracks: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&disk[i]);
    }

    printf("Enter head: ");
    scanf("%d",&disk);

    for(int i=0;i<n;i++)
    {
        totalmovement=totalmovement+abs(disk[i]-head);
        head=disk[i];
    }

    printf("%d",totalmovement);

}