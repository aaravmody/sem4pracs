#include <stdio.h>

int arr[] = {1,2,3,4,5,6,7,8,9,10,40};

int binarysearch(int low,int high,int search)
{
    if(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==search)
        {
            return mid;
        }
        else if(arr[mid]<search)
        {
            binarysearch(mid+1,high,search);
        }
        else if(arr[mid]>search)
        {
            binarysearch(low,mid-1,search);
        }
        else{
            return -1;
        }
    }
}

void main()
{
    printf("Found at index %d ",binarysearch(0,11,5));
}