#include <stdio.h>

int arr[10]={2,34,25,1,4,23,98},b[10],n=7;

void merge(int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
            b[k]=arr[i];
            k++;
            i++;
        }
        else{
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        b[k]=arr[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        b[k]=arr[j];
        j++;
        k++;
    }

    i=low;
    for(int f=0;f<k;f++)
    {
        arr[i]=b[f];
        i++;
    }
}

int mergesort(int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,high);
    }
}

void selection(){
    for(int i=0;i<n;i++)
    {
        int tempi=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[tempi])
            {
                tempi=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[tempi];
        arr[tempi]=temp;
    }
}

void insertion()
{
    int key;
    for(int i=0;i<n;i++)
    {
        int j=i-1;
        key=arr[i];
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void main()
{
    // mergesort(0,n-1);
    // selection();
    insertion();
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}