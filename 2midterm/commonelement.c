// Task 1 
// Find the Intersection Point of Two Sorted Arrays 
// Problem: Given two sorted arrays A and B, find the first common element (or return -1 if none exist).

#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return -1;
}

int findIntersection(int arr1[], int n1, int arr2[], int n2) {
    for (int i = 0; i < n1; i++) {
        int foundIndex = binarySearch(arr2, 0, n2 - 1, arr1[i]);
        if (foundIndex != -1)
            return arr1[i];
    }
    
    return -1;
}

int main() {
    int arr1[] = {1, 3, 5, 7, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int arr2[] = {2, 3, 6, 7, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int result = findIntersection(arr1, n1, arr2, n2);

    if (result == -1) {
        printf("There are no common elements in these arrays.\n");
    } else {
        printf("Common element is %d\n", result);
    }
    
    return 0;
}
