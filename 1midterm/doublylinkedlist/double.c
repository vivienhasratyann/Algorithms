#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node * createNode (int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

// Function to print the list forward
void printListForward(struct Node * head)
{
    struct Node * temp = head;
    printf("Forward List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print the list backwards
void printListBackward(struct Node * third)
{
    struct Node * temp = third;
    printf("Backward List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main(){
    struct Node * head = createNode(1);
    struct Node * second = createNode(2);
    struct Node * third = createNode(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    
    printListForward(head);
    printListBackward(third);
}