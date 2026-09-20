#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1000

typedef struct TreeNode{
    int data;
    struct TreeNode *firstChild;
    struct TreeNode *nextSibling;
} TreeNode;

TreeNode *createNode(int data){
    TreeNode*node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->firstChild = NULL;
    node->nextSibling = NULL;
    return node;
}
void addChild(TreeNode *parent, TreeNode *child){
    if (parent->firstChild == NULL){
        parent->firstChild = child;
    }
    else{
        TreeNode*c = parent->firstChild;
        while (c->nextSibling!=NULL){
            c=c->nextSibling;
        }
        c->nextSibling=child;
    } 
}

typedef struct Stack{
    TreeNode *arr[MAX];
    int top_index;
} Stack;

void init(Stack *s){
    s->top_index = -1;
}

bool isEmpty(Stack *s){
    return s->top_index == -1;
}

bool isFull(Stack *s){
    return s->top_index == MAX-1;
}

void push(Stack *s, TreeNode *value){
    if(isFull(s)){
        printf("is full");
        return;
    }
    s->arr[++s->top_index] = value;
}

void pop(Stack *s){
    if (isEmpty(s))
    {
        printf("is empty");
        return;
    }
    s->top_index--;
}

TreeNode *top(Stack *s){
    if(isEmpty(s)){
        return NULL;
    }

    return s->arr[s->top_index];
}

void dfs(TreeNode *head){
    if(head == NULL) return;

    Stack s;
    init(&s);
    push(&s, head);

    while(!isEmpty(&s)){
        TreeNode *t=top(&s);
        printf("%d", t->data);
        pop(&s);

        TreeNode *children[MAX];
        int count = 0;
        TreeNode *c = t->firstChild;
        while(c!=NULL){
            children[count++] = c;
            c = c->nextSibling;
        }

        for (int i=count-1;i>=0; i--){
            push(&s,children[i]);
        } 
    }
}

int main(){
    TreeNode *n1 = createNode(1);
    TreeNode *n2 = createNode(2);
    TreeNode *n3 = createNode(3);
    TreeNode *n4 = createNode(4);


    addChild(n1,n2);
    addChild(n2,n3);
    addChild(n3,n4);

    printf("DFS: ");
    dfs(n1);
    printf("\n");

    return 0;
}
