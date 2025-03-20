#include <stdio.h>
#include <stdlib.h> // Required for rand()

// Function to swap two elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array using Lomuto partition scheme
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If current element is smaller than pivot
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Place pivot at the correct position
    return i + 1;
}

// Function for randomized partition (improves worst-case performance)
int randomizedPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(&arr[randomIndex], &arr[high]); // Swap random pivot with last element
    return partition(arr, low, high);
}

// Function to implement QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high); // Randomized partition index

        quickSort(arr, low, pi - 1); // Sort elements before partition
        quickSort(arr, pi + 1, high); // Sort elements after partition
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 12, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}

// I used sources for implementation and didn't fully understand it 