#include <stdio.h>

void insertion(int arr[], int n){
    for (int i = 0; i < n; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
    
}

int main(){
    int arr[] = {12, 14, 16, 91, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion(arr, n);
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
    
}