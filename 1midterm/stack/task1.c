#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Stack{
    char arr[MAX_SIZE];
    int top;
};


void createEmptyStack(struct Stack *s){
    s->top = -1;
}


int isFull(struct Stack *s){
    return (s->top == MAX_SIZE - 1);
}


int isEmpty(struct Stack *s){
    return (s->top == -1);
}


void push(struct Stack *s, char x){
    if(isFull(s)){
        printf("Stack is full.\n");
        return;
    } else {
        s->top++;
        s->arr[s->top] = x;
    }
}


char pop(struct Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty.\n");
        return '\0'; // Return null character so that we can be sure that it is empty
    } else {
        char popped = s->arr[s->top];
        s->top--;
        return popped;
    }
}

int isBalanced(char *expression){
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    createEmptyStack(s);

    int i = 0;

   
    while(expression[i] != '\0'){
        char current = expression[i];
        
        // if current character is an opening bracket,we push it to the stack
        if (current == '(' || current == '[' || current == '{') {
            push(s, current);
        }
        // If it's a closing bracket,we check if it matches the top of the stack
        else if (current == ')' || current == ']' || current == '}'){
            char popped = pop(s);
            // If popped bracket does not match, return unbalanced
            if ((current == ')' && popped != '(') ||
                (current == ']' && popped != '[') ||
                (current == '}' && popped != '{')) {
                free(s);  
                return 0; // Not balanced
            }
        }

        i++;
    }

    // If the stack is empty after processing the whole expression, it's balanced
    int result = isEmpty(s);
    
    free(s);  
    return result;
}

int main(){

    char expression1[] = "( ( [ ] { ( ) } ) )";
    char expression2[] = "( { [ ] } )";
    char expression3[] = "( ) ( ] { }";
    
    // Check and print results for expression 1
    if (isBalanced(expression1)) {
        printf("Expression 1: '%s' is good\n", expression1);
    } else {
        printf("Expression 1: '%s' is bad\n", expression1);
    }

    // Check and print results for expression 2
    if (isBalanced(expression2)) {
        printf("Expression 2: '%s' is good\n", expression2);
    } else {
        printf("Expression 2: '%s' is bad\n", expression2);
    }

    // Check and print results for expression 3
    if (isBalanced(expression3)) {
        printf("Expression 3: '%s' is good\n", expression3);
    } else {
        printf("Expression 3: '%s' is bad\n", expression3);
    }

    return 0;
}
