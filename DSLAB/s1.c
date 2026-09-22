#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;


};

struct node *createnode(int x){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
void display(struct node *p){
    while(p!=NULL){
        printf("%d->",p->data);
        p=p->next;
    }
}
void pop(struct node * *x){
    if(x==NULL){
        printf("stack is empty");
    }
    else{
        struct node *temp;
        temp=*x;
        *x=(*x)->next;
        temp->next=NULL;
        int y=temp->data;
        free(temp);
        printf("Freed element is: %d ",y);
        
    };
}

int main(){
    struct node *top=createnode(100);
    struct node *a1=createnode(200);
    a1->next=top;
    top=a1;
    struct node *a2=createnode(300);
    a2->next=a1;
    top=a2;

    display(top);

    printf("----------------------------------------\n");

    pop(&top);
    display(top);



    






}