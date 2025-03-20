#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

//function to insert a new_node in the result list
void insertToBegin(struct Node **start_ref, int data){
    struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node)); //size of struct Node which already contains the size of integer 
    ptr1->data = data;
    ptr1->next = *start_ref;
    *start_ref = ptr1;
}

void printList(struct Node *start){
    struct Node *temp = start;
    while(temp!=NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertionSort(struct Node **start_ref){
    struct Node *sorted = NULL;//initialize sorted list
    struct Node *current = *start_ref;//traverse

    while (current != NULL){
        struct Node *next = current->next;//store next node
        if(sorted == NULL || sorted->data >= current->data){
            // Insert at the beginning if the sorted list is empty
            // or the current node should be first
            current->next = sorted;
            sorted = current;
        } else {
            // find the correct position in the sorted list
            struct Node *temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data){
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;//move to the next
    }
    *start_ref = sorted;//update the heas pointer to the sorted list
}

int main(){
    int arr[] = {8,5,3,1,7};
    struct Node *start = NULL;

    for (int i = 0; i < 5; i++){
        insertToBegin(&start, arr[i]);
    }

    printList(start);

    insertionSort(&start);

    printList(start);

    return 0;
}