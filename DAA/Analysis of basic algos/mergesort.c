#include <stdio.h>
#define n 8

int arr[]={23,32,45,3,564,75,22,1},B[n];

void merge(int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=high)
    {
        if(arr[i]>arr[j])
        {
            B[k]=arr[j];
            k++;
            j++;
        }
        else{
            B[k]=arr[i];
            k++;
            i++;
        }
    }
    while(i<=mid)
    {
        B[k]=arr[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        B[k]=arr[j];
        k++;
        j++;
    }
    i=low;
    for(int f=0;f<k;f++)
    {
        arr[i]=B[f];
        i++;
    }
}

void mergesort(int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
}

void main()
{
    mergesort(0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}