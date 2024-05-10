#include <stdio.h>
#define n 3

int frames[n];
int pages[12]={1,5,7,6,3,5,1,2,5,9,7,8};

void main()
{
    int miss=0,hit=0,k=0;
    for(int i=0;i<12;i++)
    {
        int pagefound=0;
        for(int j=0;j<n;j++)
        {
            if(pages[i]==frames[j])
            {
                hit++;
                break;
            }
        }
        if(!pagefound)
        {
            miss++;
            frames[k]=pages[i];
            k=(k+1)%n;
        }
    }

    printf("Number of miss %d . NUmber of hits %d ",miss,hit);


}