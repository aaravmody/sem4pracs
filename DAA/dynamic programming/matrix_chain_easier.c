#include <stdio.h>
#define MAX_SIZE 100

int d[MAX_SIZE];
int cost[MAX_SIZE][MAX_SIZE];
int parent[MAX_SIZE][MAX_SIZE];

void PrintOptimalParents(int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
    }
    else
    {
        printf("(");
        PrintOptimalParents(i, parent[i][j]);
        PrintOptimalParents(parent[i][j] + 1, j);
        printf(")");
    }
}

int main()
{
    int n;
    printf("Enter number of matrices: ");
    scanf("%d", &n);
    printf("Enter dimensions of matrices (d[i] = row of matrix i, column of matrix i+1):\n");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &d[i]);
    }

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            cost[i][j] = 1 << 30;
            
            for (int k = i; k < j; k++)
            {
                int new_cost = cost[i][k] + cost[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (new_cost < cost[i][j])
                {
                    cost[i][j] = new_cost;
                    parent[i][j] = k;
                }
            }
        }
    }

    printf("Minimum cost:\n%d\n", cost[1][n]);
    printf("Optimal Parenthesization:\n");
    PrintOptimalParents(1, n);

    return 0;
}