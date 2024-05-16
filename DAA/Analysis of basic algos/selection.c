#include <stdio.h>
#define n 8
int arr[]={23,32,45,3,564,75,22,1};


void selection()
{
    int imin,i,j,temp;
    for(i=0;i<n;i++)
    {
        imin=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[imin])
            {
                imin=j;
            }
        }
        temp=arr[imin];
        arr[imin]=arr[i];
        arr[i]=temp;
    }
    
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

}

void main()
{
    selection(arr);
}

