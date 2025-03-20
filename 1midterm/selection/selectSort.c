#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { 
        int min_j = i; 
        int min_x = arr[i]; 

        for (int j = i + 1; j < n; j++) { 
            if (arr[j] < min_x) {
                min_j = j;
                min_x = arr[j];
            }
        }
        arr[min_j] = arr[i];
        arr[i] = min_x;
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {20, 15, 12, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}
