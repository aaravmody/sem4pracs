#include <stdio.h>

int arr[]= {5,3,4,9,2,15,22,41};
void findminmax(int arr[],int n)
{
    int min=820;
    int max=-100;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    printf("Max is %d , min is %d",max,min);
}

void main()
{
    findminmax(arr,8);
}