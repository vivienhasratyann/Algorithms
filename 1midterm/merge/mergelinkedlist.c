#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Splitting the linked list into 2 halves
struct Node* split(struct Node* head){
    struct Node* fast = head; // pointer moves two nodes at a time
    // fast = fast->next->next
    struct Node* slow = head; // pointer moves one node at a time
    // slow = slow->next

    // until fast reaches the end
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        if (fast != NULL){
            slow = slow->next;
        }
    }
    struct Node* temp = slow->next;
    slow->next = NULL;
    return temp;
}

// merging two sorted linked lists
struct Node* merge(struct Node* first, struct Node* second){
    // if either list empty -> return the other list
    if (first == NULL) return second;
    if (second == NULL) return first;

    // smallest between first and second nodes
    if (first->data < second->data){
        // recursively merge the rest
        // link the result to the current node
        first->next = merge(first->next, second);
        return first;
    }
    else{
        second->next = merge(first, second->next);
        return second;
    }
}

struct Node* mergeSort(struct Node* head){
    // if the list is empty or has one node: it's already sorted
    if (head == NULL || head->next == NULL){
        return head;
    }

    struct Node* second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    return merge(head, second);
}

void printList(struct Node* head){
    struct Node* curr = head;
    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

struct Node* createNode(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int main(){
    struct Node* head = createNode(9);
    head->next = createNode(8);
    head->next->next = createNode(5);
    head->next->next->next = createNode(2);

    head = mergeSort(head);
    printList(head);

    return 0;
}