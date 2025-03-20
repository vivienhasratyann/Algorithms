// Sort following array = {5, 1, 4, 2, 8} using Bubble Sort function

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap (int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    // temp = *(arr + 1);
    // *(arr + i) = *(arr + j);
    // *(arr + j) = *(arr + i);
}

void bubbleSort(int arr[], int n){
    for (int i=0; i<n-1; i++){
        bool  swapped = false;
        for (int j = 0; i<n-i-1; j++){
            if (arr[j]>arr[j+1]){
                swap(arr, j, j+1);
                swapped = true;
            }
        }
if (swapped == false) break;  
    }
}

int main(){
    int arr[] = {5,1,4,2,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    for (int i=0;i<n;i++){
        printf("%d", arr[i]);
    }
}