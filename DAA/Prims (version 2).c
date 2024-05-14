#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define SIZE 4

int min(int d[], int visited[])
{
    int min = INT_MAX;
    int minIndex;
    for (int i = 0; i < SIZE; i++)
    {
        if (visited[i] == 0 && d[i] < min)
        {
            minIndex = i;
            min = d[i];
        }
    }
    return minIndex;
}
void prims(int w[SIZE][SIZE])
{
    int visited[SIZE];
    int parent[SIZE];
    int d[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        visited[i] = 0;
        d[i] = INT_MAX;
    }
    d[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < SIZE; i++)
    {
        int minIndex = min(d, visited);
        visited[minIndex] = 1;
        for (int j = 0; j < SIZE; j++)
        {
            if (w[minIndex][j] != 0 && visited[j] == 0 && d[j] > w[minIndex][j])
            {
                d[j] =w[minIndex][j];
                parent[j] = minIndex;
            }
        }
    }
    for (int i = 1; i < SIZE; i++)
    {
        printf("Parent(%d) - Vertex(%d) \t%d \n", (parent[i]+1), i+1, d[i]);
    }
}

void main()
{
    int w[SIZE][SIZE] = {{0, 1, 5, 2},
                         {1, 0, 0, 0},
                         {5, 0, 0, 3},
                         {2, 0, 3, 0}
        
    };
    prims(w);
}