#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
}*head=NULL;

void printCL(){
    if (head==NULL){
        printf("List is empty!\n");
        return;
    }
    struct Node* temp=head;
    printf(" > ");
    do{
        printf("%d > ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("*\n");
}

void inserE(){
    struct Node* newNode=malloc(sizeof(struct Node));
    printf("Enter the value: ");
    scanf("%d",&newNode->data);
    if (head==NULL){
        head=newNode;
        newNode->next=head;
        return;
    }
    struct Node* temp=head;
    while(temp->next!=head)
        temp=temp->next;
    newNode->next=head;
    temp->next=newNode;

}
void insert(){
    struct Node* newNode=malloc(sizeof(struct Node));
    printf("Enter the value: ");
    scanf("%d",&newNode->data);
    if (head==NULL){
        head=newNode;
        newNode->next=head;
        return;
    }
    struct Node* temp=head;
    while (temp->next!=head)
        temp=temp->next;
    newNode->next=head;
    temp->next=newNode;
}
void insertPos(){
    int position;
    struct Node* newNode=malloc(sizeof(struct Node));
    printf("Enter the value and position: ");
    scanf("%d %d",&newNode->data,&position);
    if (head==NULL){
        head=newNode;
        newNode->next=head;
        return;
    }
    struct Node* temp=head;
    for (int i=1;i<position-1;i++)
        temp=temp->next;
    newNode->next=temp->next;
    temp->next=newNode;
    
}


int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        inserE();
    printf("Original list: ");
    printCL();
    //insertBng();
    insert();
    printf("Final CLL: ");
    printCL();


    return 0;
}