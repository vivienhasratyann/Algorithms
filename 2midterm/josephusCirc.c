#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createList(int n){
    Node* head = (Node*)malloc(sizeof(Node));
    Node* temp = head;

    head->data = 1;
    for (int i = 2; i <= n; i++){
        temp->next = (Node*)malloc(sizeof(Node));
        temp = temp->next;
        temp->data = i;
    }
    temp->next = head;

    return head; 
}

int josephus(Node* head, int k, int n ){
    Node *curr = head, *prev = NULL;
    int count;

    while (n>1){
        count = 1;
        while(count != k){
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        free(curr);
        curr = prev->next;
        n--;
    }
    return curr->data;
}

int main(){
    int n = 7;
    int k = 3;

    Node* head = createList(n);

    int last = josephus(head, k, n);
    printf("Last remaining person'd index is %d\n", last);

    return 0;
}