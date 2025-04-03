#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    int priority;
    struct Node* next;
}Node;


Node *head = NULL;


void insert(int data, int priority){
    Node*temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;

    if (!head || priority < head->priority)
    {
        temp->next = head;
        head = temp;
    } else {
        Node *current = head;
        while (current->next && current->next->priority <= priority)
        {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
}

int deleteHighestPriority(){
    if (!head) return -1;
    
    int data = head->data;
    Node *temp = head;
    head = head->next;
    free(temp);
    return data;
}

int main(){
    insert(50, 6);
    insert(10, 5);
    insert(5, 3);
    insert(20, 10);

    int n = deleteHighestPriority();
    printf("Deleted: %d\n\n", n);

    // Traverse the linked list and print remaining elements
    Node* current = head;
    while (current) {
        printf("%d - %d\n", current->data, current->priority);
        current = current->next;
    }

    return 0;
}