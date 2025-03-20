// Sort following array = {5, 1, 4, 2, 8} using Bubble Sort function

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next; //linking to the next one

};

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
}

void swap(struct Node *a, struct Node *b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(struct Node *start){
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    if(start == NULL){
        return;
    }
    do{
        swapped = 0;
        ptr1 = start;
        while(ptr1->next != lptr){
            if(ptr1->data > ptr1->next->data){
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped);
}

int main(){
    int arr[]={1,2,3,4,5};
    struct Node *start = NULL;
    for (int i = 0; i<6; i++){
        insertToBegin(&start, arr[i]);
    }
    printList(start);
    bubbleSort(start);
    printf("\n");
    printList(start);
    printf("\n");
}
