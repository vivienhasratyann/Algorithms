#include <stdio.h>
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *reverse(struct Node *curr) {
  
    if (curr == NULL) return NULL;

    struct Node *temp = curr->prev;
    curr->prev = curr->next;
    curr->next = temp;

    if (curr->prev == NULL) return curr;

    return reverse(curr->prev);
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node *createNode(int new_data) { 
    struct Node *new_node = 
      (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

int main() {
  
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;

    printf("Original Linked list\n");
    printList(head);
    head = reverse(head);
    printf("Reversed Linked list\n");
    printList(head);

    return 0;
}
