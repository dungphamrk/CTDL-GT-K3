#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        root = createNode(value);
        return root;
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

    void inorderTraversal(Node* root) {
    if (root == NULL) return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}
void printLevel2Nodes(Node* root, int level) {
    if (root == NULL) return;

    if (level == 2) {
        printf("%d ", root->data);
    } else {
        printLevel2Nodes(root->left, level + 1);
        printLevel2Nodes(root->right, level + 1);
    }
}


int main() {
    Node* root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    printLevel2Nodes(root,0);

    return 0;
}
