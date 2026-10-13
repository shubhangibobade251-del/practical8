#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into Binary Search Tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    else if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Inorder Traversal: Left, Root, Right
void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder Traversal: Root, Left, Right
void preorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, value, choice;

    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\n1. Inorder Traversal");
    printf("\n2. Preorder Traversal");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Inorder: ");
        inorder(root);
        printf("\n");
    }
    else if (choice == 2) {
        printf("Preorder: ");
        preorder(root);
        printf("\n");
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}