#include <stdio.h>

// Swaping 2 elements
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Finding the Minimum Index Recursively

// this function finds the index of the smallest element in the subarray from index i to j.
int minIndex(int arr[], int i, int j){
    if (i == j) // this means there is only one element left, so return i
        return i; 
    int k = minIndex(arr, i+1, j); // Recursively find the minimum index in the subarray [i+1, j] and store it in k.
    if (arr[i] < arr[k])
        return i;
    else
        return k; 

}

// Recursive Selection Sort
void selectionSort(int arr[], int n, int index){
    if (index == n)
        return; // the sorting is complete, so return

    int k = minIndex(arr, index, n-1); // find the index of the smallest element
    if (k != index)
        swap(&arr[k], &arr[index]); 

    selectionSort(arr, n, index+1);
}

// Printing the Array
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n, 0);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
