#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n,head,totalmovement,temp,total,add;
    int disk[10];
    printf("Enter number of disk tracks: ");
    scanf("%d",&n);

    printf("Enter total: ");
    scanf("%d",&total);

    printf("Enter the disk tracks: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&disk[i]);
    }

    printf("Enter head: ");
    scanf("%d",&head);
    disk[n]=head;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(disk[j]>disk[j+1])
            {
                temp=disk[j];
                disk[j]=disk[j+1];
                disk[j+1]=temp;
            }
        }
    }

    for(int i=0;i<=n;i++)
    {
        printf("%d ",disk[i]);
    }

    for(int i=0;i<n;i++)
    {
        if(disk[i]<head)
        {
            add=disk[i];
        }
    }


    totalmovement+=(abs(head-total)+total+add);
    printf("%d",totalmovement);
}