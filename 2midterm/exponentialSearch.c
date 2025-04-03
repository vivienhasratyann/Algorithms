// Exponential Search Algorithm
#include <stdio.h>
#include <math.h>

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

int exponentialSearch(int arr[], int n, int x){
    if(arr[0] == x)
        return 0;
    int i = 1;
    while(i < n && arr[i] <= x)
        i = i*2;
    return binarySearch(arr, i/2, fmin(i, n-1), x);
}

// kam min-i poxaren petqa lracucich if petq a grenq vor arr-ic durs chganq 

int main(){
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = exponentialSearch(arr, n, x);
    if(result == -1){
        printf("Element is not present \n");
    }
    else{
        printf("Element is present at index %d\n", result);
    }
    
    return 0;
}