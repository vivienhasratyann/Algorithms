#include <stdio.h>

void swap(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectionSort(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        int min_ind = i;
        for (int j = min_ind+1; j < n; j++){
            if (arr[min_ind]>arr[j]){
                min_ind = j;
            }
            
        }
        swap(arr, min_ind, i);
        
    }
    
}

int main(){
    int arr[] = {13, 64, 2, 76, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;    
}