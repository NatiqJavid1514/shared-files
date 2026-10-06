#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *right;
    struct node *left;
};

struct node* createnode(int x){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void insertnode(struct node *y, struct node *&root){
    if(root == NULL){
        root = y;
        return;
    }

    if(y->data > root->data){
        insertnode(y, root->right);
    }
    else if(y->data < root->data){
        insertnode(y, root->left);
    }
}

void inorder(struct node *root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root){
    if(root == NULL){
        return;
    }

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

bool searchroot(struct node *root, int key){
    if(root == NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }

    if(key < root->data){
        return searchroot(root->left, key);
    }
    else{
        return searchroot(root->right, key);
    }
}

struct node* deleteNode(int x, struct node* root){

    if(root == NULL)
        return NULL;

      {
        root->left = deleteNode(x, root->left);
    }
    else if(x > root->data){
        root->right = deleteNode(x, root->right);
    }
    else{

        // No child
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }

        // Only right child
        else if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        // Only left child
        else if(root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Two children
        else{
            struct node* temp = root->right;

            while(temp->left != NULL)
                temp = temp->left;

            root->data = temp->data;

            root->right = deleteNode(temp->data, root->right);
        }
    }

    return root;
}

int main(){

    struct node *root = createnode(100);

    root->right = createnode(150);
    root->left = createnode(70);

    root->right->left = createnode(140);
    root->right->right = createnode(200);

    root->left->right = createnode(90);
    root->left->left = createnode(50);

    inorder(root);

    struct node *x = createnode(600);
    insertnode(x, root);

    printf("\nAfter insertion: ");
    inorder(root);

    printf("\nSearch 140: %d", searchroot(root, 140));

    root = deleteNode(150, root);

    printf("\nAfter deletion: ");
    inorder(root);

    return 0;
}