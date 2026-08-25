#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};
int isempty(struct stack *p){
    if(p->top==-1){
        return 1;
    }
    return 0;
}
int isfull(struct stack *p){
    if(p->top==(p->size)-1){
        return 1;

    }
    return 0;
};

int main(){
    struct stack *s;
    s->size=6;
    s->top=-1;
    s->arr=(int *)malloc(s->size*(sizeof(int))); //pointer use karna why? taaki isko use karsaku
    if(isempty){
        s->arr[0]=10;
        s->top++;
    }
    printf("%d",s->arr[0]);


}