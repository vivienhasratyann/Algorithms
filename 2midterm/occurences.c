// Task 2
// Find the First and Last Occurrence of a Number 
// Problem: Given a sorted array of numbers, find the indices of the first and last occurrence of a given number X. 

#include <stdio.h>

int findFirstOccurrence(int arr[], int n, int X) {
    int low = 0, high = n - 1, result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == X) {
            result = mid;
            high = mid - 1; 
        } 
        else if (arr[mid] < X) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    
    return result;
}

int findLastOccurrence(int arr[], int n, int X) {
    int low = 0, high = n - 1, result = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == X) {
            result = mid;
            low = mid + 1;
        } 
        else if (arr[mid] < X) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    
    return result;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 2;
    
    int first = findFirstOccurrence(arr, n, X);
    int last = findLastOccurrence(arr, n, X);
    
    if (first == -1) {
        printf("Number %d not found in the array.\n", X);
    } 
    else {
        printf("First occurrence: %d, Last occurrence: %d\n", first, last);
    }
    
    return 0;
}
