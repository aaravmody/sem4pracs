#include <stdio.h>
#define n 5

int map[5][5]={
    {0,4,7,9,8},
    {4,0,1,0,0},
    {7,1,0,2,0},
    {9,0,2,0,6},
    {8,0,0,6,0}
};

int dist[5],par[5],source=0,visited[5];

int extractmin()
{
    int temp=10000,tempi=-1;
    for(int i=0;i<5;i++)
    {
        if(dist[i]<temp && visited[i]!=1)
        {
            temp=dist[i];
            tempi=i;
        }
    }
    return tempi;
}

void initialise()
{
    for(int i=0;i<n;i++)
    {
        dist[i]=999;
        par[i]=-1;
        visited[i]=0;
    }
    dist[source]=0;
}

void relax(int u,int v)
{
        if(dist[v]>dist[u]+map[u][v])
        {
            dist[v]=dist[u]+map[u][v];
            par[v]=u;
        }
    }


void djikstra()
{
    initialise();
    int u;
    for(int i=0;i<n;i++)
    {
       u=extractmin();
    for(int j=0;j<n;j++)
    {
        if(visited[j]==0 && map[u][j]!=0)
        {
            relax(u,j);
        }
    }
    visited[u]=1;
    }
}

void main()
{
    djikstra();
    for(int i=0;i<n;i++)
    {
        printf("%d",dist[i]);
    }

    for(int i=0;i<n;i++)
    {
        printf("%d",par[i]);
    }
}