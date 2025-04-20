#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_INPUT_LENGTH 100 // Increased buffer size

// Structure to store student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    float gpa;
    int socialFactor;
    float score;
} Student;

// Function to calculate the scholarship score
float calculateScore(float gpa, int socialFactor) {
    return gpa * 0.7 + socialFactor * 0.3;
}

// Function to heapify (maintain heap property) - Max Heap
void maxHeapify(Student arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].score > arr[largest].score)
        largest = left;

    if (right < n && arr[right].score > arr[largest].score)
        largest = right;

    if (largest != i) {
        // Swap arr[i] and arr[largest]
        Student temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        maxHeapify(arr, n, largest);
    }
}

// Function to build a max-heap
void buildMaxHeap(Student arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

// Function to sort the array using heap sort (for extracting top K)
void heapSort(Student arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        // Swap arr[0] (max element) with arr[i]
        Student temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        maxHeapify(arr, i, 0);
    }
}

int main() {
    int n, k;
    char inputBuffer[MAX_INPUT_LENGTH];

    // Read input for N and K
    printf("Enter the number of students (N) and the number of scholarships (K): ");
    if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL || sscanf(inputBuffer, "%d %d", &n, &k) != 2) {
        fprintf(stderr, "Error: Invalid input for N and K\n");
        return 1;
    }

    if (n <= 0 || k <= 0) {
        fprintf(stderr, "Error: N and K must be positive integers.\n");
        return 1;
    }

    Student students[n];

    // Read input for each student
    for (int i = 0; i < n; i++) {
        printf("Enter name, GPA, and social factor for student %d: ", i + 1);
        if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL || sscanf(inputBuffer, "%s %f %d", students[i].name, &students[i].gpa, &students[i].socialFactor) != 3) {
            fprintf(stderr, "Error: Invalid input for student %d\n", i + 1);
            return 1;
        }
        students[i].score = calculateScore(students[i].gpa, students[i].socialFactor);
    }

    // Sort students by score using heap sort (max-heap)
    heapSort(students, n);

    // Output the top K students
    printf("\nTop %d Students:\n", k);
    for (int i = 0; i < k && i < n; i++) {
        printf("%s %.2f\n", students[i].name, students[i].score);
    }

    return 0;
}