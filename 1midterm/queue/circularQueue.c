#include <stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

int isFull(){
    return (rear + 1) % SIZE == front;
}

int isEmpty(){
    return front == -1;
}

void enqueue(int data){
    if(isFull()){
        printf("Queue overflow\n");
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    items[rear] = data;
    printf("Element %d inserted\n", data);
}

int dequeue(){
    if (isEmpty()){
        printf("Queue is underflow\n");
        return -1;
    }
    int data = items[front];
    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1) % SIZE;
    }
    return data;
}

void display(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (i != rear){
        printf("%d ", items[i]);
        i = (i + 1) % SIZE;
    // ensures that i correctly moves forward in a circular manner:
    // If i reaches the end of the array (SIZE - 1), the modulus operation (% SIZE) resets i to 0, allowing for a circular queue behavior.
    }
    printf("%d\n", items[rear]);
}     

void displayArr(){ // already has some elements in it like 0 (with the size of 5 given)
    printf("Array elements: ");
    for( int i = 0; i < SIZE; i++){
        printf("%d ", items[i]);
    }
    printf("\n");
}

int main(){
    displayArr();
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();
    displayArr();

    printf("Dequeued element: %d\n", dequeue());
    display();

    return 0;
}
