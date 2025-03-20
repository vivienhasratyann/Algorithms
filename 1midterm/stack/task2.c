// Write a function that reverses a string by pushing and popping its letters on a s.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

typedef struct {
    int arr[MAX_SIZE];
    int top;
} st;

void initialize(st *s){
    s->top = -1;
}

int isFull(st *s){
    return s->top == MAX_SIZE - 1;
}

int isEmpty(st *s){
    return s->top == -1;
}

// Add a new character onto the stack
void push(st *s, char value){
    if (isFull(s)){
        printf("Stack is full\n");
    } else{
        s->top++;
        s->arr[s->top] = value;
    }
}
// Remove last chararcter from the stack
char pop(st *s){
    if (isEmpty(s)){
        printf("Stack is empty\n");
        return '\0';
    } else {
        return s->arr[s->top--];
    }
}

// Reverse the string 
void reverseString(char str[]){
    st s;
    initialize(&s);

    //push each character onto the stack
    for (int i = 0; i < strlen(str); i++)
    {
        push(&s, str[i]);
    }
    
    //pop each character from the stack and place it back in the string 
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = pop(&s);
    }
}

int main(){
    char str[] = "algorithms";
    printf("Original string: %s\n", str);

    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}