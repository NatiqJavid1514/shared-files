#include <iostream>
using namespace std;

class node{
    public:
    
    int val;
    node *ptr;


    
    

    node(int n){
        this->val=n;
        ptr=NULL;

    }



};


int main(){


   node *head= new node(10);
   head->ptr=new node(20);
   head->ptr->ptr=new node(30);
   head->ptr->ptr->ptr=new node(40);
   head->ptr->ptr->ptr->ptr=new node(50);
   




//    node *n=new node(30);
//    //insertion at beginning
//    n->ptr=head;
//    head=n;
// node *temp=head;
// while(temp->ptr!=NULL){
//     temp=temp->ptr;
// }
// temp->ptr= new node(50);
// while(head!=NULL){
//     cout<<head->val<<endl;
//     head=head->ptr;
// }

// int position=3;
// node *temp=head;
// for(int i=1;i<position-1;i++){
//     temp=temp->ptr;
// }
// node *n= new node(1000);
// n->ptr=temp->ptr;
// temp->ptr=n;
// while(head!=NULL){
//     cout<<head->val<<endl;
//     head=head->ptr;
// }



//deletion
//for beginning 
// node *temp=head;
// head=head->ptr;
// free(temp);
// while(head!=NULL){
//     cout<<head->val<<endl;
//     head=head->ptr;
// }

//for end
// node *temp=head;
// while(temp->ptr->ptr!=NULL){
//     temp=temp->ptr;

    
// }
// node *temp2;
// temp2=temp->ptr;
// temp->ptr=NULL;
// free(temp2);
// while(head!=NULL){
//     cout<<head->val<<endl;
//     head=head->ptr;
// }
//deletion at any position.

node *temp=head;
int position=3;
node *temp2;
for(int i=1;i<position-1;i++){
    temp=temp->ptr;
    

}
 temp2=temp->ptr;
 cout<<temp->val<<endl;
 temp->ptr=temp->ptr->ptr;
 cout<<temp->ptr->val<<endl;
 temp2->ptr=NULL;
 free(temp2);
 while(head->ptr!=NULL){
    cout<<head->val<<endl;
    head=head->ptr;
 }
 
 
 




















   

    



}