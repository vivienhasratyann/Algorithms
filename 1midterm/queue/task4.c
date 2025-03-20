// Task 4: Bank Customer Queue Simulation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define MAX 50

struct Queue{
    char customers[SIZE][MAX];
    int front;
    int rear;
};

void initialize(struct Queue *q){
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q){
    return (q->front == -1);
}

int isFull(struct Queue *q){
    return (q->rear == SIZE - 1);
}

void enqueue(struct Queue *q, char* name){
    if (isFull(q)){
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    strcpy(q->customers[q->rear], name); // copying the customer’s name into the queue
    printf("Customer added: %s\n", name);
}

void dequeue(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    printf("Customer served: %s\n", q->customers[q->front]);
    if(q->front == q->rear) {
        initialize(q);
    } else {
        q->front++;
    }
}

void display(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    for ( int i = q->front; i <= q->rear; i++){
        printf("Current customer: ");
        printf("%s\n", q->customers[i]);
    }
}

int main(){
    struct Queue q;
    initialize(&q);

    enqueue(&q, "Ivan");
    enqueue(&q, "Maria");
    display(&q);

    dequeue(&q);
    display(&q);

    return 0;
}