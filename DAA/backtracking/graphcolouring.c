#include <stdio.h>
#define n 5
#define m 3

int x[n];
int graph[n][n] = {{0,1,1,0,1},
                {1,0,1,0,1},
                {1,1,0,1,0},
                {0,0,1,0,1},
                {0,1,0,1,0}};

void nextcolour(int k)
{
    while(1)
    {
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)
        {
            return;
        }
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(x[k]==x[j] && graph[k][j]!=0)
            {
                break;
            }
            count++;
        }
            if(count==n)
            {
                return;
            }
    }
}

void graphcolouring(int k)
{
    while(1)
    {
        nextcolour(k);
        if(x[k]==0)
        {
            return;
        }
        if(k==n)
        {
            printf("\n");
            for(int i=0;i<n;i++)
            {
                printf("%c : %d\t", 65+i, x[i]);
            }
        }
        else{
            graphcolouring(k+1);
        }
    }
}

void main(){
    for(int i=0; i<n; i++){
        x[i] = 0;
    }
    graphcolouring(0);
}