#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    bool lthread; // true if 'left' is a thread (points to inorder predecessor)
    bool rthread; // true if 'right' is a thread (points to inorder successor)
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->lthread = true; // Initially, pointers act as threads pointing to NULL
    temp->rthread = true;
    return temp;
}

// Function to insert a new node into the Threaded BST
struct Node* insert(struct Node* root, int data) {
    struct Node* ptr = root;
    struct Node* parent = NULL; // Parent of key to be inserted

    // Search for the insertion point
    while (ptr != NULL) {
        // If key already exists, return
        if (data == ptr->data) {
            printf("Duplicate key %d not inserted.\n", data);
            return root;
        }

        parent = ptr; // Update parent pointer

        // Move to the left subtree
        if (data < ptr->data) {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        // Move to the right subtree
        else {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }

    // Create the new node
    struct Node* tmp = createNode(data);

    if (parent == NULL) {
        root = tmp;
    }
    else if (data < parent->data) {
        // Setup links and threads for the left child
        tmp->left = parent->left;
        tmp->right = parent;
        parent->lthread = false;
        parent->left = tmp;
    }
    else {
        // Setup links and threads for the right child
        tmp->left = parent;
        tmp->right = parent->right;
        parent->rthread = false;
        parent->right = tmp;
    }

    return root;
}

// Helper function to find the leftmost node in a subtree
struct Node* leftmost(struct Node* n) {
    if (n == NULL) return NULL;
    while (n->lthread == false) {
        n = n->left;
    }
    return n;
}

// Non-recursive function to perform Inorder Traversal using threads
void inorder(struct Node* root) {
    if (root == NULL) return;

    // Find the starting node (leftmost element of the entire tree)
    struct Node* curr = leftmost(root);

    while (curr != NULL) {
        printf("%d ", curr->data);

        // If the right pointer is a thread, it points directly to the successor
        if (curr->rthread) {
            curr = curr->right;
        }
        // Otherwise, the successor is the leftmost node of the right subtree
        else {
            curr = leftmost(curr->right);
        }
    }
    printf("\n");
}

int main() {
    struct Node* root = NULL;

    // Insert elements into the Threaded BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder Traversal of the Threaded Binary Tree:\n");
    inorder(root);

    return 0;
}