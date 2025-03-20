// Implement a Queue Using a Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Queue{
    struct Node* front;
    struct Node* rear;
};

void initialize(struct Queue *q){
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(struct Queue *q){
    return(q->front == NULL);
}

void enqueue(struct Queue *q, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL){
        printf("Memory allocation failed. Queue is full.\n");
        return;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (isEmpty(q)){
        q->front = newNode;
        q->rear = newNode;
    } else {
        newNode->prev = q->rear;
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueue %d\n", value);
}

void dequeue(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Dequeue %d\n", temp->data);

    q->front = q->front->next;

    if (q->front == NULL){
        q->rear = NULL;
    } else {
        q->front->prev = NULL;
    }
    free(temp);
}

void peek(struct Queue* q){
    if (isEmpty(q)){
        printf("Queue is empty. Cannot peek.\n");
        return;
    }
    printf("Front element: %d\n", q->front->data);
}

int isFull(struct Queue* q){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL){
        return 1;
    }
    free(temp);
    return 0;
}

void destroyQueue(struct Queue* q){
    while (!isEmpty(q)) {
        dequeue(q);
    }
}

int main() {
    struct Queue q;
    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    peek(&q);

    dequeue(&q);

    destroyQueue(&q);
    return 0;
}
