#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree with root at index i
void heapify(int a[], int n, int i) {
    int largest = i;  // Root node
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child exists and is greater than root
    if (left < n && a[left] > a[largest])
        largest = left;

    // Check if right child exists and is greater than root
    if (right < n && a[right] > a[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

// Function to implement heap sort
void heapSort(int a[], int n) {
    // Build max heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // Extract elements one by one from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(&a[0], &a[i]);
        heapify(a, i, 0);  // Heapify the reduced heap
    }
}

// Function to print array elements
void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");  // Add newline for better readability
}

int main() {
    int a[] = {48, 10, 23, 43, 28, 26, 1};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting array elements are:\n");
    printArr(a, n);

    heapSort(a, n);

    printf("\n");
    printf("After sorting array elements are:\n");
    printArr(a, n);

    return 0;
}

// I used sources for implementation and didn't fully understand it 