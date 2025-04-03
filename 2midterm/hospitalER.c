#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100

typedef struct {
    int data;
    int priority;
} Patient;

Patient queue[MAX];
int size = 0;

void insertion(int data, int priority) {
    if (size == MAX) {
        printf("Queue is full\n");
        return;
    }
    queue[size].data = data;
    queue[size].priority = priority;
    size++;
}

int getHighestPriorityIndex(){
    int min = INT_MAX;
    int index = 1;
    for(int i = 0; i < size; i++){
        if(queue[i].priority<min){
            min = queue[i].priority;
            index= i;
        }
    }
    return index;
}

int deleteHighestPriority() {
    if (size == 0) return -1;
    int index = getHighestPriorityIndex();
    int data = queue[index].data;
    for (int i = index; i < size - 1; i++) {
        queue[i] = queue[i + 1];
    }
    size--; 
    return data;
}

// եթե priority-ն կրկնվում է, ապա այն դուրս է բերոմ առաջին հանդիպածին

int main() {
    int choice, patient_id, priority;

    while (1) {
        printf("\nEmergency Room Menu:\n");
        printf("1. Add Patient\n");
        printf("2. Treat Next Patient (Highest Priority)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Patient ID: ");
            scanf("%d", &patient_id);
            printf("Enter Priority (lower number = higher priority): ");
            scanf("%d", &priority);
            insertion(patient_id, priority);
        } else if (choice == 2) {
            int treated_id = deleteHighestPriority();
            if (treated_id != -1) {
                printf("Treating Patient ID: %d\n", treated_id);
            } else {
                printf("No patients in the emergency room.\n");
            }
        } else if (choice == 3) {
            break; 
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}