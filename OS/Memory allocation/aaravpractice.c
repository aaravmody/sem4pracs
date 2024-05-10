#include <stdio.h>

struct process{
    int size,isfilled;
}pq[10];

struct memory{
    int size,isfilled;
}mem[10];

void main()
{
    int pno,memno;
    printf("no of process: ");
    scanf("%d",&pno);

    printf("No of memory: ");
    scanf("%d",&memno);

    for(int i=0;i<pno;i++)
    {
        printf("Process ka bhar: ");
        scanf("%d",&pq[i].size);
    }

    for(int i=0;i<memno;i++)
    {
        printf("Memory ka bhar: ");
        scanf("%d",&mem[i].size);
    }

    for(int i=0;i<memno;i++)
    {
        for(int j=0;j<memno-i-1;j++)
        {
            if(mem[j].size>mem[j+1].size)
            {
                struct memory temp = mem[j];
                mem[j]=mem[j+1];
                mem[j+1]=temp;
            }
        }
    }

    for(int i=0;i<pno;i++)
    {
        for(int j=0;j<memno;j++)
        {
            if(pq[i].size<=mem[j].size && pq[i].isfilled!=1 && mem[j].isfilled!=1)
            {
                pq[i].isfilled=1;
                mem[j].isfilled=1;
                printf("Filled %d in %d\n",pq[i],mem[j]);
                mem[j].size=mem[j].size-pq[i].size;
            }
        }
    }
}