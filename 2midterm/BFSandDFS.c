#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

typedef struct TreeNode {
    int value;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
} TreeNode;


TreeNode* nodeQueue[SIZE]; // queue for BFS
int head = 0, tail = -1;

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = val;
    newNode->leftChild = newNode->rightChild = NULL;
    return newNode;
}

// enqueue
void addToQueue(TreeNode* node) {
    if (node != NULL)
        nodeQueue[++tail] = node;
}

// dequeue
TreeNode* removeFromQueue() {
    if (head <= tail)
        return nodeQueue[head++];
    return NULL;
}

// DFS recursive
bool searchDFS(TreeNode* rootNode, int target) {
    if (rootNode == NULL) return false;
    if (rootNode->value == target) return true;
    return searchDFS(rootNode->leftChild, target) || searchDFS(rootNode->rightChild, target);
}

// BFS with queue
bool searchBFS(TreeNode* rootNode, int target) {
    head = 0;
    tail = -1;
    addToQueue(rootNode);
    while (head <= tail) {
        TreeNode* currentNode = removeFromQueue();
        if (currentNode->value == target) return true;
        addToQueue(currentNode->leftChild);
        addToQueue(currentNode->rightChild);
    }
    return false;
}

int main() {
    TreeNode* root = createNode(10);
    root->leftChild = createNode(4);
    root->rightChild = createNode(15);
    root->leftChild->leftChild = createNode(2);
    root->leftChild->rightChild = createNode(6);
    root->rightChild->rightChild = createNode(20);

    int numberToFind;
    printf("Enter the number to find in the binary tree: ");
    scanf("%d", &numberToFind);

    if (searchDFS(root, numberToFind))
        printf("DFS: %d is in the tree.\n", numberToFind);
    else
        printf("DFS: %d is NOT in the tree.\n", numberToFind);

    if (searchBFS(root, numberToFind))
        printf("BFS: %d is in the tree.\n", numberToFind);
    else
        printf("BFS: %d is NOT in the tree.\n", numberToFind);

    return 0;
}


// comparing bfs and dfs 

//        10
//       /  \
//      4   15
//     / \    \
//    2   6    20

// DFS Order: 10 → 4 → 2 → 6 → 15 → 20
// BFS Order: 10 → 4 → 15 → 2 → 6 → 20