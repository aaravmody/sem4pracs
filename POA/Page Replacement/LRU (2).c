#include <stdio.h>

int pages[14]= {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
int frames[3];
int timestamp[3];

void main()
{
    int hit=0,miss=0,count=0;
    for(int i=0;i<3;i++)
    {
        frames[i]=-1;
    }

    for(int i=0;i<3;i++)
    {
        timestamp[i]=-1;
    }

    
    for(int i=0;i<14;i++)
    {
        int s=0;
        for(int j=0;j<3;j++)
        {
            if(frames[j]==pages[i])
            {
                hit++;
                s++;
                timestamp[j]=i;
                break;
            }
        }
        if(s==0)
        {
            miss++;
            int least=0;
            for(int j=0;j<3;j++)
            {
                if(timestamp[j]<timestamp[least])
                {
                    least=j;
                }
            }
            frames[least]=pages[i];
            timestamp[least]=i;
        }

        for(int j=0;j<3;j++)
        {
            if(frames[j]!=-1)
            {
                printf("%d  ",frames[j]);
            }
            else{
                printf("-  ");
            }
        }
        printf("\n");
    }
    printf("%d , %d",miss,hit);
}