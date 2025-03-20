#include <stdio.h>
#include <string.h>

// structure for a student
typedef struct {
    char name[50]; // student name
    int grade;     // student grade
} Student;

// bubble sort for student structures array
void bubbleSort(Student arr[], int n, int *comparisons, int *swaps) {
    int i, j;
    *comparisons = 0; // comparison counter
    *swaps = 0;       // swap counter

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*comparisons)++; // count each comparison
            //comparing by grade or by name if grades are equal
            if (arr[j].grade < arr[j + 1].grade || 
                (arr[j].grade == arr[j + 1].grade && strcmp(arr[j].name, arr[j + 1].name) > 0)) {
                // swap students
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swaps)++; // count swap
            }
        }
    }
}

// printing sorted array of students
void printStudents(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", arr[i].name, arr[i].grade);
    }
}

int main() {
    // Input: Array of students
    Student students[] = {
        {"Alice", 85},
        {"Bob", 70},
        {"Charlie", 90},
        {"Diana", 75}
    };
    int n = sizeof(students) / sizeof(students[0]); //number of students
    int comparisons, swaps; // storing total comparisons and swaps

    // sorting the array
    bubbleSort(students, n, &comparisons, &swaps);

    // output the sorted array
    printf("Sorted list of students:\n");
    printStudents(students, n);

    // output comparisons and swaps
    printf("Number of comparisons: %d\n", comparisons);
    printf("Number of swaps: %d\n", swaps);

    return 0;
}
