#include <stdio.h>
#include <string.h>

int arr[10][10],p[10][10];
char a[20]="abcdefg";
char b[20]="def";
char m,n;

void lcs()
{
    char m=strlen(a);
    char n=strlen(b);
    for(int i=0;i<m;i++)
    {
        arr[i][0]=0;
    }
    for(int i=0;i<m;i++)
    {
        arr[0][i]=0;
    }

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(a[i-1]==b[j-1])
            {
                arr[i][j]=arr[i-1][j-1]+1;
                p[i][j]='d';
            }
            if(arr[i-1][j]>=arr[i][j-1])
            {
                arr[i][j]=arr[i-1][j];
                p[i][j]='u';
            }
            else
            {
                arr[i][j]=arr[i][j-1];
                p[i][j]='l';
            }
        }
    }
}

void printlcs(int i,int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    if(p[i][j]=='d')
    {
        printlcs(i-1,j-1);
        printf("%c",a[i-1]);
    }
    if(p[i][j]=='u')
    {
        printlcs(i-1,j);
    }
    if(p[i][j]=='l')
    {
        printlcs(i,j-1);
    }
}


void main()
{
    lcs();
    printlcs(m,n);
}