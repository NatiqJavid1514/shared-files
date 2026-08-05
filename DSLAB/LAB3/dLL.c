#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
    
}
*start=NULL;
void insert_beg(){
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter an element: \n");
    scanf("%d",&p->data);
    if(start==NULL){
        p->prev=NULL;
        p->next=NULL;
        start=p;
    }
    else{
        p->prev=NULL;
        p->next=start;
        start->prev=p;
        start=p;

    }
}
void insert_end() {
    struct node*p,*temp=start;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter an element\n");
    scanf("%d",&p->data);
    if(start==NULL){
        p->prev=NULL;
        p->next=NULL;
        start=NULL;

    }
    while(temp->next!=NULL){
        temp=temp->next;



    }
            temp->next=p;

        p->prev=temp;
        p->next=NULL;
}
void insert_specific(){
    struct node *p,*temp=start,*t;
    int pos,i;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter the position of new element\n");
    scanf("%d",&pos);
    for(i=1;i<pos;i++){
        t=temp;

    }
    if(temp==NULL){
        printf("position does not exist");
    }
    else{
        temp=temp->next;

    }
    if(temp!=NULL){
        printf("Enter an element\n");
        scanf("%d",&p->data);
        t->next=p;
        p->prev=t;
        p->next=temp;
        temp->prev=p;
    }
}