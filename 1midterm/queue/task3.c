// Task 3: Simulate a Printer Queue 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define MAX 50

struct Queue{
    char documents[SIZE][MAX];
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
        printf("Printer queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    strcpy(q->documents[q->rear], name); // copying the document's name into the queue
    printf("Added document: %s\n", name);
}

void dequeue(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    printf("Printing document: %s\n", q->documents[q->front]);
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
    printf("Documents in queue:\n");
    for ( int i = q->front; i <= q->rear; i++){
        printf("%d. %s\n", i - q->front + 1, q->documents[i]);
    }
}

int main(){
    struct Queue q;
    initialize(&q);

    enqueue(&q, "report.pdf");
    enqueue(&q, "hw1.c");
    display(&q);

    dequeue(&q);
    display(&q);

    dequeue(&q);
    display(&q);

    return 0;
}