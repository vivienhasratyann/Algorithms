// Sort array = [] using insertionSort
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j]>key){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    } 
}

void printArray(int arr[], int n){
    for (int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {7,12,1,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}