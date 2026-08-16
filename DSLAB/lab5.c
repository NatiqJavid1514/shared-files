#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node *createnode(int newdata){
    struct Node*newnode=(struct Node *)malloc(sizeof(struct Node));
    newnode->data=newdata;
    newnode->next=NULL;
    return newnode;
};


int main(){
    struct Node *head=createnode(100);
    head->next=createnode(200);
    head->next->next=createnode(300);
    head->next->next->next=createnode(400);
    struct Node *temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    
    temp->next=head;

    //deletion at beginning
struct Node *oldhead = head;
struct Node *temp1 = head;

while (temp1->next != head)
    temp1 = temp1->next;

head = head->next;
temp1->next = head;

free(oldhead);
struct Node *temp2 = head;

do {
    printf("%d ", temp2->data);
    temp2 = temp2->next;
} while (temp2 != head);
    




}




