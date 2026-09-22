#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
int stack[MAXSIZE];
int top=-1;


int main(){
    
    //for push operation;
    if(top==-1){
        printf("Stack is empty, you need to push elements into the stack\n");
        
        for(int i=0;i<MAXSIZE;i++){
            scanf("%d",&stack[i]);
            top++;
        }




    }
    else{
        top=top+1;
        printf("Enter the element you want to insert: ");
        scanf("%d",&stack[top]);

        
    }
  
    //traversal
    // printf("Stack elements are: ");
    // for(int i=top;i>=0;i--){
    //     printf("%d ",stack[top]);
    //     top--;

    // };
    // poping elements from stack;
    if(top==-1){
        printf("Stack is empty cannot pop ");
    }
    else{
        printf("The removed element is %d",stack[top]);
        top--;
    }





}


