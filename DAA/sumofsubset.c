#include <stdio.h>
#define n 7

int x[n], m = 35, w[n] = {15,7,20,5,18,10,12};

int sumofsubset(int i,int s,int r)
{
    x[i]=1;
    if((s+w[i])==m)
    {
        printf("\n");
        for(int f=0;f<=i;f++)
        {
            printf("%d ",w[f]*x[f]);
        }
        for(int j=i+1;j<n;j++)
        {
            printf("%d ",0);
        }
    }
    else if((s+w[i]+w[i+1])<=m)
    {
        sumofsubset(i+1,s+w[i],r-w[i]);
    }

    if((s + w[i+1]) <= m && (s + r - w[i]) >= m){
        x[i] = 0;
        sumofsubset(i+1,s,r-w[i]);
    }
}


void main(){
    int s=0,r=0;
    for (int i=0; i<n; i++){
        r += w[i];
        x[i] = 0;
    }
    sumofsubset(0,s,r);
}