#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *createnode(int d){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->next;
    newnode->prev;
    return newnode;
    

}
void printLL(struct node *h){
    while(h!=NULL){
        printf("%d ->",h->data);
        h=h->next;
    }
}

int main(){
    
    struct node *n0=createnode(100);
    struct node *head=n0;
    struct node *n1=createnode(200);
    struct node *n2=createnode(300);
    struct node *n3=createnode(400);
    
    head->next=n1;
    head->prev=NULL;
    n1->prev=head;
    n1->next=n2;
    n2->prev=n1;
    n2->next=n3;
    n3->prev=n2;
    n3->next=NULL; 

    //deletion at beginning
    // struct node *temp=head;
    // head=head->next;
    // temp->next=NULL;
    // head->prev=NULL;
    // free(temp);
    // printLL(head);

    //deletion at end
    // struct node*temp=head;
    // struct node*temp2;
    // while(temp->next->next!=NULL){
    //     temp=temp->next;


    // }
    // temp2=temp->next;
    // temp->next=NULL;
    // temp2->prev=NULL;
    // free(temp2);
    // printLL(head);


    //deletion at any point


    //deletion at any point;
    int position=3;
    
    struct node*temp=head;
    struct node*temp2;
    for(int i=1;i<position-1;i++){
        temp=temp->next;

    }
    temp2=temp->next;
    temp->next=temp2->next;
    temp2->next->prev=temp;
    free(temp2);
    printLL(head);


    
    







}