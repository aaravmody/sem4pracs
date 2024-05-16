#include <stdio.h>

#include <string.h>

int pi[10];

void cmp(char *p)
{
    int k=0;
    pi[0]=0;
    int n=strlen(p);
    for(int i=1;i<n;i++)
    {
        while(k!=0 && p[k]!=p[i])
        {
            k=pi[k-1];
        }
        if(p[k]==p[i])
        {
            k++;
        }
        pi[i]=k;
    }
}

void kmp(char *t,char *p)
{
    int m=strlen(t);
    int n=strlen(p);
    cmp(p);
    int q=1;
    for(int i=0;i<m;i++)
    {
        while(q!=0 && p[q]!=t[i])
        {
            q=pi[q];
        }
        if(p[q]==t[i])
        {
            q++;
        }
        if(q==n)
        {
            printf("Pattern at %d \n",i-n+1);
            q=pi[q];

        }
    }
}

int main() {
    kmp("abcdbcebce", "bceb");
    return 0;
}