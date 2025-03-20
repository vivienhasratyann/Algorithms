#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x){
    while(low<=high){
        int mid = low + (high - low) / 2;

        if (arr[mid] == x){
            return mid;
        }
        else if(arr[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }  
    }
    return -1;
}

int main(){
    int arr[] = {2, 5, 8, 13, 17, 23, 36};
    int x = 23;
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