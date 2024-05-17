#include <stdio.h>

#define MAX 999

int cost[5][5] = {
    {0, 4, 7, 9, 8},
    {4, 0, 1, 0, 0},
    {7, 1, 0, 2, 0},
    {9, 0, 2, 0, 6},
    {8, 0, 0, 6, 0},
};

int main()
{
    int n = 5;
    int ne = 1;
    int mincost = 0;
    int visited[5] = {0};

    printf("The edges of Minimum Cost Spanning Tree are\n");
    // start from 0
    visited[0] = 1;
    while (ne < n)
    {
        int min = MAX;
        int a = -1, b = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] != 0)
                    {
                        if (cost[i][j] < min)
                        {
                            min = cost[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
            }
        }

        if (a != -1 && b != -1)
        {
            printf("%d edge (%d,%d) = %d\n", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }
    }

    printf("\n\tMinimum cost = %d\n", mincost);
    return 0;
}