#include <stdio.h>

struct process{
    int space,isfilled;
}pq[10];

struct memory{
    int space,isfilled;
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
        pq[i].isfilled=0;
    }

    printf("Enter memory ka space");
    for(int i=0;i<memspace;i++)
    {
        scanf("%d",&mem[i].space);
        mem[i].isfilled=0;
    }

    struct memory temp;
    for(int i=0;i<memspace-1;i++)
    {
        for(int j=0;j<memspace-i-1;j++)
        {
            if(mem[j].space>mem[j+1].space)
            {
                temp=mem[j];
                mem[j]=mem[j+1];
                mem[j+1]=temp;
            }
        }
    }

    for(int i=0;i<memspace;i++)
    {
        printf("%d \n",mem[i].space);
    }
    for(int i=0;i<pro;i++)
    {
        for(int j=0;j<memspace;j++)
        {
            if(pq[i].space<=mem[j].space && pq[i].isfilled!=1 && mem[j].isfilled!=1)
            {
                pq[i].isfilled=1;
                mem[j].isfilled=1;
                printf("%d is filled in %d \n",pq[i].space,mem[j].space);
                break;
            }
        }
    }
    

}