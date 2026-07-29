#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *createnode(int newdata){
    struct node*newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->next=NULL;
    return newnode;
}
int main(){
    // struct node *head=createnode(100);

    // head->next=createnode(200);
    // head->next->next=createnode(300);

    // //insert element at end;
    // struct node *temp=head;
    // while(temp->next!=NULL){
    //     temp=temp->next;
    // }
    // temp->next=createnode(400);

    // insert at beginning

    // struct node *head=createnode(50);
    // struct node *newhead=createnode(10);
    // if(head->next==NULL){
        
    //     newhead->next=head;

    // };
    // printf("%d",newhead->data);

    
    //insert at any position;

    // struct node *head=createnode(50);
    // head->next=createnode(60);
    // head->next->next=createnode(70);
    // head->next->next->next=createnode(80);
    // struct node *temp=head;
    // int position=3;
    // for(int i=1;i<(position-1)&&temp->next!=NULL;i++){
    //     temp=temp->next;




    // }
    // struct node *temp2=temp->next
    // temp->next=createnode(65);
    // temp->next->next=temp2;

    //deletion
    //     struct node *head=createnode(50);
    // head->next=createnode(60);
    // head->next->next=createnode(70);
    // head->next->next->next=createnode(80);

    // //deletion at beginning
    // struct node *temp=head;
    // head=head->next;
    // free(temp);

    //deletion at end
    // struct node *head=createnode(50);
    // head->next=createnode(60);
    // head->next->next=createnode(70);
    // head->next->next->next=createnode(80);
    
    // struct node *temp=head;
    // if(head==NULL){
    //     return;
    // }
    // if(head->next=NULL){
    //     free(head);
    //     head=NULL;
    //     return
    // }
    
    // while(temp->next->next!=NULL){
    //     temp=temp->next;
    // }
    // free(temp->next);
    // temp->next=NULL;

    //deleting at any point 
        struct node *head=createnode(50);
    head->next=createnode(60);
    head->next->next=createnode(70);
    head->next->next->next=createnode(80);
    struct node *temp=head;
    int position=2;
    for(int i=1;i<(position-1);i++){
        temp=temp->next;
        
    }
    struct node *delete=temp->next;
    temp->next=temp->next->next;
    free(delete);
     
    




    
    






    


    

}
    
