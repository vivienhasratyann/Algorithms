#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100

typedef struct TreeNode{
    int data;
    struct TreeNode *firstChild;
    struct TreeNode *nextSibling;
} TreeNode;

TreeNode *createNode(int data){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data=data;
    node->firstChild = NULL;
    return node;
}

void addChild(TreeNode *parent, TreeNode *child){
    if(parent->firstChild==NULL){
        parent->firstChild=child;
    }
    else{
        TreeNode *c = parent->firstChild;
        while(c->nextSibling!=NULL){
            c=c->nextSibling;
        }
        c->nextSibling=child;
    }
}

// bfs for Tree
typedef struct Queue{
    TreeNode *arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

void init(Queue *q){
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q){
    return q->front == -1 || q->front>q->rear;
}

bool isFull(Queue *q){
    return q->rear==MAX_SIZE-1;
}

void enqueue(Queue *qu, TreeNode *value){
    if(isFull(qu)){
        printf("Queue is full");
        return;
    }
    if(isEmpty(qu)){
        qu->front=0;
    }
    qu->arr[qu->rear] = value;
    return;
}

TreeNode *dequeue(Queue *qu){
    if(isEmpty(qu)){
        printf("Queue is empty");
        return;
    }
    qu->front++;
    if(qu->front>qu->rear){
        init(qu);
    }
}

TreeNode *front(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty");
        return NULL;
    }
    return q->arr[q->front];
}

void bfs(TreeNode *head){
    if(head == NULL){
        return;
    }
    Queue q;
    init(&q);
    enqueue(&q, head);

    while(!isEmpty(&q)){
        TreeNode *current = dequeue(&q);
        printf("%d ", current->data);
        // dequeue(&s);

        TreeNode *child = current->firstChild;
        while(child){
            enqueue(&q, child);
            child = child->nextSibling;
        }
    }

}

int main(){
    TreeNode *n1 = createNode(1);
    TreeNode *n2 = createNode(2);
    TreeNode *n3 = createNode(3);
    TreeNode *n4 = createNode(4);
    TreeNode *n5 = createNode(5);
    TreeNode *n6 = createNode(6);

    addChild(n1, n2);
    addChild(n1, n3);
    addChild(n1, n4);
    addChild(n2, n5);
    addChild(n3, n6);

    bfs(n1);
    printf("\n");

    return 0;
}


