#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isBSTUtil(struct TreeNode* node, int min, int max) {
    if (node == NULL)
        return true;

    if (node->val < min || node->val > max)
        return false;

    return isBSTUtil(node->left, min, node->val - 1) &&  
           isBSTUtil(node->right, node->val + 1, max);   
}

bool isBST(struct TreeNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int main() {
    struct TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    if (isBST(root))
        printf("The tree is a BST.\n");
    else
        printf("The tree is not a BST.\n");

    return 0;
}