#include <stdio.h>

struct process{
    int space;
}pq[10];

struct memory{
    int space;
}mem[10];

void main()
{

    int pro,memspace;
    printf("Enter no of process: ");
    scanf("%d",&pro);

    printf("Enter no of memory space");
    scanf("%d",&memspace);

    printf("Enter process ka space");
    for(int i=0;i<pro;i++)
    {
        scanf("%d",&pq[i].space);
        
    }

    printf("Enter memory ka space");
    for(int i=0;i<memspace;i++)
    {
        scanf("%d",&mem[i].space);
    }

    for(int i=0;i<pro;i++)
    {
        int prev=-1;
        for(int j=(prev+1)%memspace;j<memspace;j++)
        {
            if(pq[i].space<=mem[j].space)
            {
                printf("%d is filled in %d M%d \n",pq[i].space,mem[j].space,j+1);
                mem[j].space-=pq[i].space;
                prev=j;
                break;
            }
        }
    }   
}