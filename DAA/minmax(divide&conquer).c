#include <stdio.h>

int arr[] = {10,9,8,7,6,5,4,3,2,1};

void minMax(int low, int high, int *min, int *max){
    if(low == high){
        *min = arr[low];
        *max = arr[high];
    }
    else if(low == high-1){
        if(arr[low] < arr[high]){
            *min = arr[low];
            *max = arr[high];
        }
        else{
            *min = arr[high];
            *max = arr[low];
        }
    }
    else{
        int min1, max1;
        int mid = (low + high)/2;
        minMax(low, mid, min, max);
        minMax(mid+1, high, &min1, &max1);
        if(max1 > *max){
            *max = max1;
        }
        if(min1 < *min){
            *min = min1;
        }
    }
}

void main(){
    int min, max;
    minMax(0,10-1, &min, &max);
    printf("min : %d, max : %d", min, max);
}