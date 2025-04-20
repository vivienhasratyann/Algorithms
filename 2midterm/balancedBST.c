#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;  
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = arr[mid];

    root->left = sortedArrayToBST(arr, start, mid - 1);  
    root->right = sortedArrayToBST(arr, mid + 1, end);  

    return root;
}

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void printTree(struct TreeNode* root) {
    if (root == NULL) return;
    printTree(root->left);
    printf("%d ", root->val);
    printTree(root->right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct TreeNode* root = sortedArrayToBST(arr, 0, n - 1);  

    printf("Balanced BST (Inorder Traversal): ");
    printTree(root);
    printf("\n");

    return 0;
}