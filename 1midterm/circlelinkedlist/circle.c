#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node * createNode (int data){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next=NULL;
    return newNode;
}

// Function to print the list
void printList(struct Node * first)
{
    struct Node * temp = first->next;
    struct Node * last = first;
    printf("Forward List: ");
    printf("%d", last->data);
    while (temp != last) {
        printf("%d ", temp->data);
        temp = temp->next;

    }
}


int main(){
    struct Node * first = createNode(1);
    struct Node * second = createNode(2);
    struct Node * third = createNode(3);

    first->next = second;
    second->next = third;
    third->next = first;
    
    printList(first);

}