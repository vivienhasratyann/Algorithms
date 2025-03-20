// Use a stack to convert a decimal number into the binary system. 
#include <stdio.h>
#include <stdlib.h>

#define MAX 50 

typedef struct {
    int items[MAX];
    int top;
}stack;

void initialize(stack *s){
    s->top = -1;
}

int isEmpty(stack *s){
    return s->top == -1;
}

int isFull(stack *s){
    return s->top == MAX - 1;
}

void push(stack *s, int item){
    if (isFull(s))
    {
       printf("Stack is full\n");
    } else {
        s->top++;
        s->items[s->top] = item;
    }  
}

int pop(stack *s){
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->items[s->top--];
    }   
}

void decimalToBinary(int num){
    stack s;
    initialize(&s);

    if (num == 0){
        printf("Binary: 0\n");
        return;
    }

    while (num > 0){
        push(&s, num % 2);
        num /= 2;
    }

    printf("Binary: ");
    while (!isEmpty(&s)){
        printf("%d", pop(&s));
    }
    printf("\n");
}

int main(){
    int num = 53;
    printf("Decimal: %d\n", num);

    decimalToBinary(num);

    return 0;
}