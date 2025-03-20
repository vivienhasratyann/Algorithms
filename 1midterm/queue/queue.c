// Queue - first in first out FIFO
#include <stdio.h>
#define SIZE 1000

struct Queue {
    int queue[SIZE];
    int front;
    int rear;
} Queue;

void initializeQueue(struct Queue *q){
    q->front = -1;
    q->rear = -1;
};
int isEmpty (struct Queue *q){
    return (q->rear==-1);
}
int isFull(struct Queue *q){
    return (q->rear==SIZE-1);
}

void enQueue(struct Queue *q, int data){
    if(isFull(q)){
        printf("\nQueue is Full");
        return;
    }
    if(isEmpty(q)){
        q->front=0;
    }
    q->rear++;
    q->queue[q->rear] = data;
    printf("\nEnqueued element %d", data);  
}

void deQueue(struct Queue *q){
    if(isEmpty(q)){
        printf("\nQueue is Empty");
        return;
    }
    int data=q->queue[q->front];
    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;
    }
    else{
        q->front++;
    }
    printf("\nDeleted element id %d", data);
    return;    

}

void display(struct Queue *q){
    if(isEmpty(q)){
        printf("\nQueue is empty");
        return;
    }
    for (int i = q->front; i<=q->rear;i++){
        printf("%d", q->queue[i]);
    }
    printf("\n");
}

int main(){
    struct Queue q;
    initializeQueue(&q);
    enQueue(&q, 1);
    enQueue(&q, 2);
    enQueue(&q, 3);
    enQueue(&q, 4);
    enQueue(&q, 5);
    enQueue(&q, 6);
    display(&q);
    deQueue(&q);
    deQueue(&q);
    deQueue(&q);
    deQueue(&q);
    display(&q);
}