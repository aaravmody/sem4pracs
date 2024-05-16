#include <stdio.h>
#include <stdlib.h>

int x[4];

int place(int k, int i)
{
    for(int j=0;j<k;j++)
    {
        if(x[j]==i || abs(x[j]-i)==abs(j-k))
        {
            return 0;
        }
    }
    return 1;
}

void nqueen(int k, int n){
    for(int i=0;i<n;i++)
    {
        if(place(k,i)==1)
        {
            x[k]=i;
            if(k==n-1)
            {
                for(int p=0; p<n; p++)
                printf("%d ", x[p]);
                printf("\n");
            }
            else
                nqueen(k+1,n);
        }
    }
}

void main()
{
    nqueen(0,4);
}
