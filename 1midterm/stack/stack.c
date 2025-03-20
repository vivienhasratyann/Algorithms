#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Stack{
    int items[MAX];
    int top;
};
typedef struct Stack st; 

void CreateEmptystack(st *s){
     s->top==-1;
}
int isEmpty(st *s){
    if(s->top==-1) {return 1;}
    else{
        return 0;
        
    }
}

int isFull(st *s){
    if(s->top==MAX-1){ return 1;}
    else{ return 0;}
 
}

void push(st *s, int newItem){
    if(isFull(s)){
        printf("Stack is full\n");
    }
    else {
        s->top++;
        s->items[s->top]=newItem;
    }
}

void pop(st *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        printf("%d\n",s->items[s->top]);
        s->top--;
        
    }
}

int main(){
    st *s=(st*)malloc(sizeof(st));
    CreateEmptystack(s);
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    push(s,6);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
}
