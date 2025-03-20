#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int arr[], int n){
    for (int i = 0; i < n; i++){
        int key = arr[i];
        int j = i-1;

        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    
}

int main(){
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    InsertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
    
}