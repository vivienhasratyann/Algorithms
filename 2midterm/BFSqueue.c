//////// BFS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100  // Maximum size for the queue

// Tree node definition for a general tree
typedef struct TreeNode {
	int data;
	struct TreeNode *firstChild;
	struct TreeNode *nextSiblings;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int data) {
	TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = data;
	node->firstChild = NULL;
	node->nextSiblings = NULL;
	return node;
}

// Adds a child to a parent node (as last sibling if others exist)
void addChild(TreeNode *parent, TreeNode *child) {
	if (parent->firstChild == NULL) {
		parent->firstChild = child;
	} else {
		TreeNode *c = parent->firstChild;
		while (c->nextSiblings != NULL) {
			c = c->nextSiblings;
		}
		c->nextSiblings = child;
	}
}

// Queue structure for BFS traversal
typedef struct Queue {
	TreeNode *arr[MAX_SIZE];
	int front;
	int rear;
} Queue;

// Initialize the queue
void init(Queue *qu) {
	qu->front = -1;
	qu->rear = -1;
}

// Check if the queue is empty
bool isEmpty(Queue *qu) {
	return (qu->front == -1 || qu->front > qu->rear);
}

// Check if the queue is full
bool isFull(Queue *qu) {
	return (qu->rear == MAX_SIZE - 1);
}

// Add a node to the queue
void enqueue(Queue *qu, TreeNode *node) {
	if (isFull(qu)) {
		printf("Queue is full\n");
		return;
	}
	if (isEmpty(qu)) {
		qu->front = 0;
	}
	qu->arr[++qu->rear] = node;
}

// Remove a node from the queue
void dequeue(Queue *qu) {
	if (isEmpty(qu)) {
		printf("Queue is empty\n");
		return;
	}
	qu->front++;
	if (qu->front > qu->rear) {
		init(qu);
	}
}

// Get the node at the front of the queue
TreeNode* front(Queue *qu) {
	if (isEmpty(qu)) {
		printf("Queue is empty\n");
		return NULL;
	}
	return qu->arr[qu->front];
}

// Breadth-First Search (BFS) traversal of the tree
void bfs(TreeNode *head) {
	if (head == NULL) {
		return;
	}
	Queue q;
	init(&q);
	enqueue(&q, head);

	while (!isEmpty(&q)) {
		TreeNode *t = front(&q);
		printf("%d ", t->data);
		dequeue(&q);

		TreeNode *c = t->firstChild;
		while (c) {
			enqueue(&q, c);
			c = c->nextSiblings;
		}
	}
}

// Main function to build a tree and perform BFS
int main() {
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

	printf("BFS: ");
	bfs(n1);
	printf("\n");

	return 0;
}
