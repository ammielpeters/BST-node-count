#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Count total nodes
int countNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count leaf nodes
int countLeafNodes(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Count non-leaf nodes
int countNonLeafNodes(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 0;
    return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    printf("Total nodes: %d\n", countNodes(root));
    printf("Leaf nodes: %d\n", countLeafNodes(root));
    printf("Non-leaf nodes: %d\n", countNonLeafNodes(root));

    return 0;
}
