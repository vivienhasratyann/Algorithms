#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x){
    if(high>=low){
        int mid = low + (high - low) / 2;

        if(arr[mid] == x){
            return mid;
        }

        if(arr[mid] > x){
            return binarySearch(arr, low, mid - 1, x);
        }

        return binarySearch(arr, mid+1, high, x);
    }

    return -1;
}

int main(){
    int arr[] = {2, 5, 8, 13, 17, 23, 36};
    int x = 5;
    int low = 0;
    int high = sizeof(arr) / sizeof(arr[0]) - 1;

    int result = binarySearch(arr, low, high, x);
   
    if(result == -1){
        printf("Element is not in the array\n");
    }
    else{
        printf("Element's index is %d \n", result);
    }

    return 0;
}