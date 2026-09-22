#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;

};
struct node *createnode(int x){
    struct node*newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
void display(struct node *head){
    while(head->next!=head){
        printf("%d",head->data);
        head=head->next;
    }
}

int main(){
    struct node *head;
    head=createnode(100);
    head->next=createnode(200);
    head->next->next=createnode(300);
    head->next->next->next=createnode(400);
    head->next->next->next->next=head;
    struct node *curr=head;
    do{
        printf("%d ", curr->data);
        curr = curr->next->next;


    }
    while(curr!=head);
    return 0;





    












}