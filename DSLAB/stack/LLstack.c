#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *top = NULL;

struct node *createnewnode(int x) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void push(int x) {
    struct node *newnode = createnewnode(x);
    newnode->next = top;
    top = newnode;
    printf("Pushed %d onto the stack.\n", x);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow! The stack is empty.\n");
        return;
    }
    struct node *temp = top;
    printf("Popped %d from the stack.\n", temp->data);
    top = top->next;
    free(temp);
}

void display(struct node *p) {
    if (p == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (Top to Bottom): ");
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    push(100);
    push(200);
    push(300);
    
    printf("\n");
    display(top);
    printf("\n");
    
    pop();
    
    printf("\n");
    display(top);
    
    return 0;
}