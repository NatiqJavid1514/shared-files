#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
    
}
*start=NULL;
void delete_beg(){
    struct node *temp=start;
    if(start==NULL){
        printf("list is empty");
        
        
    }
    else{
        start=start->next;
        start->prev=NULL;
        printf("deleted element is %d",temp);
        free(temp);

    }
}
void delete_end(){
    struct node *temp=start,*t;
    if(start==NULL){
        printf("the list is empty");

    }
    else{
        while(temp->next!=NULL){
            t=temp;
            temp=temp->next;
        }
    }
    t->next=NULL;
    temp->prev=NULL;
    printf("deleted element is %d",temp->data);
    free(temp);
}