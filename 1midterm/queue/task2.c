// Task 2: Check if a Queue is a Palindrome 

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

struct Queue {
    int data[SIZE];
    int front;
    int rear;
};

void initialize(struct Queue* q){
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q){
    return (q->front == -1);
}

int isFull(struct Queue* q){
    return (q->rear == SIZE - 1);
}

void enqueue(struct Queue* q, int value){
    if (isFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
}

void display(struct Queue* q){
    if (isEmpty(q)){
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++){
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int isPalindrome(struct Queue* q){
    if(isEmpty(q)) return 1;

    int stack[SIZE];
    int top = -1;

    for (int i = q->front; i<= q->rear; i++){
        stack[++top] = q->data[i];
    }

    for (int i = q->front; i <= q->rear; i++){
        if (q->data[i] != stack[top--]){
            return 0;
        }
    }
    return 1;
}

int main(){
    struct Queue q;
    initialize(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    display(&q);
    if(isPalindrome(&q))
        printf("Result: The queue is a palindrome.\n");
    else
        printf("Result: The queue is NOT a palindrome.\n");

    return 0;
}