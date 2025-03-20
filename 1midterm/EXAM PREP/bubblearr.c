#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        bool swapped = false;
        for (int j = 0; j < n-1-i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr, j, j+1);
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        } 
    }
  
}

int main(){
    int arr[] = {4, 17, 5, 8, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
    
}