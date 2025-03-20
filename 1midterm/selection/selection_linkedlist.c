#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// insert the node in the beginning of the list 
void insertToBegin(struct Node **start_ref, int data){
    struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node)); //allocate memory for new node
    ptr1->data = data; //assign value to node
    ptr1->next = *start_ref; //link new node to the list
    *start_ref = ptr1; //update the head pointer to the new node
}

// printing the linkedlist
void printList(struct Node *start){
    struct Node *temp = start; // temp ptr to treverse
    while(temp != NULL){ 
        printf("%d ", temp->data); //print the current node data
        temp = temp->next; //move to the next
    }
}

//swap data of 2 nodes
void swap(struct Node *a, struct Node *b){
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void selectionSort(struct Node *start){
    struct Node *current = start; //pointer to traverse the list
    while(current != NULL){
        struct Node *minNode = current; //assume the current node is the min
        struct Node *temp = current->next; //checking the rest

        // Find the minimum in the unsorted list
        while (temp != NULL){
            if (temp->data < minNode->data){
                minNode = temp;
            }
            temp = temp->next;
        }

        //swap the min with the current (if it's less)
        if(minNode != current){
            swap(current, minNode);
        }

        current = current -> next; //move next
    }
}

int main(){
    int arr[] = {7, 1, 3, 5, 8};
    struct Node *start = NULL; //initializing an empty linked list

    for(int i = 0; i < 5; i++){
        insertToBegin(&start, arr[i]);
    }

    printList(start);
    printf("\n");

    selectionSort(start);

    printList(start);
    printf("\n");

    return 0;

}