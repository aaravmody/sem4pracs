#include <stdio.h>
#define n 8
int arr[]={23,32,45,3,564,75,22,1};


void selection(int arr[])
{
    for(int i=0;i<n;i++)
    {
        int min=arr[i],key=i;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                key=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[key];
        arr[key]=temp;
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

