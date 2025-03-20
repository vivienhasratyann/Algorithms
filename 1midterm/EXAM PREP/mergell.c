#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* split(struct Node* head) {
    struct Node* fast = head;
    struct Node* slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        if (fast != NULL) {
            slow = slow->next;
        }
    }

    struct Node* temp = slow->next;
    slow->next = NULL;
    return temp;
}

struct Node* merge(struct Node* first, struct Node* second) {
  
    if (first == NULL) return second;
    if (second == NULL) return first;

    if (first->data < second->data) {
        first->next = merge(first->next, second);
        return first;
    }
    else {
        second->next = merge(first, second->next);
        return second;
    }
}

struct Node* MergeSort(struct Node* head) {
  
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* second = split(head);

    head = MergeSort(head);
    second = MergeSort(second);

    return merge(head, second);
}

void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

struct Node* createNode(int x) {
    struct Node* newNode = 
      (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node* head = createNode(9);
    head->next = createNode(8);
    head->next->next = createNode(5);
    head->next->next->next = createNode(2);

    head = MergeSort(head);
    printList(head);

    return 0;
}
