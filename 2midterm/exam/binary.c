#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x){
    while(low <= high){
        int mid = low + (high - low)/2;
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid] > x){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int x = 8;
    int low = 0;
    int high = sizeof(arr) / sizeof(arr[0]) -1;

    int result = binarySearch(arr, low, high, x);
    if(result == -1){
        printf("The element is not in the array\n");
    }
    else{
        printf("Element's index is %d\n", result);
    }
    
    return 0;
}