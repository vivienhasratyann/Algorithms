// Write a program that removes consecutive duplicate characters from a string. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct{
    char arr[MAX];
    int top;
} stack;

void initialize(stack *s){
    s->top = -1;
}

int isEmpty(stack *s){
    return s->top == -1;
}

void push(stack *s, char value){
    s->top++;
    s->arr[s->top] = value;
}

char pop(stack *s){
    return s->arr[s->top--];
}

char peek (stack *s){
    return s->arr[s->top];
}

void removeDuplicates(char str[]){
    stack s;
    initialize(&s);

    int index = 0;
    for (int i = 0; i < strlen(str); i++){
        // push if the stack is empty or the top is different from the current character
        if (isEmpty(&s) || peek(&s) != str[i]){
            push(&s, str[i]);
            str[index++] = str[i]; // build result directly
        }
    }
    str[index] = '\0'; // null-terminate the result string
}

int main(){
    char str[] = "aabbccddeee";
    printf("Original string: %s\n", str);

    removeDuplicates(str);
    printf("Without duplicates: %s\n", str);

    return 0;
}
