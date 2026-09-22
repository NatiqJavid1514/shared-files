#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = 0;
int rear = -1;


void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    rear++;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}


int dequeue() {
    if (front > rear) {
        printf("Queue Underflow! Queue is empty\n");
        return -1;
    }
    int value = queue[front];
    front++;
    
 
    if (front > rear) {
        front = 0;
        rear = -1;
    }
    return value;
}


void display() {
    if (front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
};

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("Dequeued item: %d\n", dequeue());
    display();

    enqueue(40);
    enqueue(50);
    display();

    return 0;
}












    






