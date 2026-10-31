#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
    int ht;

};
int height(struct node *n){
    if(n==NULL){
        return 0;
    }
    return n->ht;
}
struct node *createNode(int data){
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    p->ht=1;
    return p;
}
int getBalanceFactor(struct node *n){
    if(n==NULL){
        return 0;
    }
    return height(n->left)-height(n->right);
}
struct node *rightRotate(struct node *y){
    struct node *x=y->left;
    struct node *T2=x->right;

    x->right=y;
    y->left=T2;

    y->ht=1+((height(y->left)>height(y->right))?height(y->left):height(y->right));
    x->ht=1+((height(x->left)>height(x->right))?height(x->left):height(x->right));

    return x;
}
struct node *leftRotate(struct node *x){
    struct node *y=x->right;
    struct node *T2=y->left;

    y->left=x;
    x->right=T2;

    x->ht=1+((height(x->left)>height(x->right))?height(x->left):height(x->right));
    y->ht=1+((height(y->left)>height(y->right))?height(y->left):height(y->right));

    return y;
}
struct node *leftRightRotate(struct node *z){
    z->left=leftRotate(z->left);
    return rightRotate(z);
}
struct node *rightLeftRotate(struct node *z){
    z->right=rightRotate(z->right);
    return leftRotate(z);
}
struct node *insertNode(struct node*root,int data){
    if(root==NULL){
        return createNode(data);
    }

    if(data< root->data){
        root->left=insertNode(root->left,data);  
    }
    
    else if (data > root->data){
        root->right=insertNode(root->right,data);   
    }
    
    root->ht=1+((height(root->left)>height(root->right))?height(root->left):height(root->right));

    int balance=getBalanceFactor(root);

    if(balance>1 && data<root->left->data){
        return rightRotate(root);
    }
    if(balance<-1 && data>root->right->data){
        return leftRotate(root);
    }
    if(balance>1 && data>root->left->data){
        return leftRightRotate(root);
    }
    if(balance<-1 && data<root->right->data){
        return rightLeftRotate(root);
    }

    return root;
}
struct node *deleteNode(struct node *root,int key){
    if(root==NULL){
        return root;
    }
    if(key<root->data){
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteNode(root->right,key);
    }
    else{
        if(root->left==NULL || root->right==NULL){
            struct node *temp=root->left?root->left:root->right;
            if(temp==NULL){
                temp=root;
                root=NULL;
            }
            else{
                *root=*temp;
            }
            free(temp);
        }
        else{
            struct node *temp=root->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }

    if(root==NULL){
        return root;
    }

    root->ht=1+((height(root->left)>height(root->right))?height(root->left):height(root->right));

    int balance=getBalanceFactor(root);

    if(balance>1 && getBalanceFactor(root->left)>=0){
        return rightRotate(root);
    }
    if(balance<-1 && getBalanceFactor(root->right)<=0){
        return leftRotate(root);
    }
    if(balance>1 && getBalanceFactor(root->left)<0){
        return leftRightRotate(root);
    }
    if(balance<-1 && getBalanceFactor(root->right)>0){
        return rightLeftRotate(root);
    }

    return root;
}
struct node *search(struct node *root,int key){
    if(root==NULL || root->data==key){
        return root;
    }
    if(key<root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
        
    }
}
void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main(){
    struct node *root=NULL;
    int choice,data;
    while(1){
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data to insert: ");
                scanf("%d",&data);
                root=insertNode(root,data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d",&data);
                root=deleteNode(root,data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d",&data);
                struct node *result=search(root,data);
                if(result!=NULL){
                    printf("Element %d found in the tree.\n",data);
                }
                else{
                    printf("Element %d not found in the tree.\n",data);
                }
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}