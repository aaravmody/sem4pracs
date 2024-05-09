#include <stdio.h>
#define n 8

int arr[]={23,42,56,2,49,11,33,59};

void insertion(int arr[])
{
    for(int i=1;i<n;i++)
    {
        int temp=arr[i];
        int j=i-1;
        while((temp<arr[j])&&(j>=0))
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

void main()
{
    insertion(arr);
}