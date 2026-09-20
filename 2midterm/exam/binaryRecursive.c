#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x){
    if(high >= low){
        int mid = (low + high) /2;

        if(arr[mid] == x){
            return mid;
        }
        if(arr[mid] > x){
            return binarySearch(arr, low, mid - 1, x);
        }
        else{
            return binarySearch(arr, mid + 1, high, x);
        }
    }
    return -1;
}

int main(){
    int arr[] = {7, 15, 23, 37, 41, 50, 78};
    int x = 41;
    int low = 0;
    int high = sizeof(arr) / sizeof(arr[0]) - 1;

    int result = binarySearch(arr, low, high, x);

    if(result == -1){
        printf("The element is not in the array");
    }
    else{
        printf("Element's index is %d \n", result);
    }


    return 0;
}