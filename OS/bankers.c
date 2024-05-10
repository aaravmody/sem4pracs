#include <stdio.h>

int allocation[5][3] = {
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2},
};

int max[5][3] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3},
};
int visited[5] = {0};
int need[5][3];
int available[3] = {3, 3, 2};
int safeSequence[5];
int count = 0;

void calculateNeed()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<3;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
}

int isSafe(int process)
{
    for(int i=0;i<3;i++)
    {
        if(need[process][i]>available[i])
        {
            return 0;
        }
    }
    return 1;
}

void bankers()
{
    calculateNeed();
    while(count<5)
    {
        int found=0;
        for(int i=0;i<5;i++)
        {
            if(!visited[i]&&isSafe(i))
            {
                for(int j=0;j<3;j++)
                {
                    available[j]+=allocation[i][j];
                }
                safeSequence[count++]=i;
                visited[i]=1;
                found=1;
                break;
            }
        }

        if(!found)
        {
            printf("No safe sequence");
            return;
        }
    }
     printf("Safe sequence present: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", safeSequence[i]);
    }
    printf("\n");
}

void main()
{
    bankers();
}