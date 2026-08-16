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


    //insertion at beginning
    if(head==NULL){
        printf("List is empty\n");
        
    }
    
  struct node *beg=createnode(600);
  beg->next=head;
  head->prev=beg;
  beg->prev=NULL;
  head=beg;
//printLL(head);

//insertion at end;
// struct node *end=createnode(100000);
// while(head->next!=NULL){
//     head=head->next;
// }

// head->next=end;
// end->prev=head;
// end->next=NULL;
// head=beg;
// printLL(head);


//insertion at any point
//printLL(head);
struct node *btw=createnode(888);
int position=3;
struct node *temp=head;
struct node *temp2;

for(int i=1;i<position-1;i++){
    temp=temp->next;

}
temp2=temp->next;
temp->next=btw;
btw->prev=temp;
btw->next=temp2;
temp2->prev=btw;
printLL(head);











    
}
