#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeg(int x) {
    struct Node *new = malloc(sizeof(struct Node));
    new->data = x;

    if (head == NULL) {
        head = new;
        new->next = new;
        new->prev = new;
    } else {
        struct Node *last = head->prev;

        new->next = head;
        new->prev = last;
        last->next = new;
        head->prev = new;
        head = new;
    }
}

void insertEnd(int x) {
    struct Node *new = malloc(sizeof(struct Node));
    new->data = x;

    if (head == NULL) {
        head = new;
        new->next = new;
        new->prev = new;
    } else {
        struct Node *last = head->prev;

        new->next = head;
        new->prev = last;
        last->next = new;
        head->prev =new;
    }
}

void insertPos(int x, int pos) {
    if (pos == 1) {
        insertBeg(x);
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    struct Node *new = malloc(sizeof(struct Node));
    new->data = x;

    new->next = temp->next;
    new->prev = temp;

    temp->next->prev = new;
    temp->next = new;
}

void deleteBeg() {
    if (head == NULL)
        return;

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    struct Node *last = head->prev;

    head = head->next;
    head->prev = last;
    last->next = head;

    free(temp);
}

void deleteEnd() {
    if (head == NULL)
        return;

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct Node *last = head->prev;

    last->prev->next = head;
    head->prev = last->prev;

    free(last);
}

void deletePos(int pos) {
    if (pos == 1) {
        deleteBeg();
        return;
    }

    struct Node *temp = head;

    for (int i = 1; i < pos; i++)
        temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}

void display() {
    struct Node *temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {

    // Initial linked list: 10 20 30
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    printf("Initial List: ");
    display();

    int choice, type, value, pos;

    printf("\n1. Insert");
    printf("\n2. Delete");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {

        printf("Enter value: ");
        scanf("%d", &value);

        printf("\n1. Beginning");
        printf("\n2. End");
        printf("\n3. Specific Position");
        printf("\nEnter choice: ");
        scanf("%d", &type);

        if (type == 1)
            insertBeg(value);

        else if (type == 2)
            insertEnd(value);

        else if (type == 3) {
            printf("Enter position: ");
            scanf("%d", &pos);
            insertPos(value, pos);
        }
    }

    else if (choice == 2) {

        printf("\n1. Beginning");
        printf("\n2. End");
        printf("\n3. Specific Position");
        printf("\nEnter choice: ");
        scanf("%d", &type);

        if (type == 1)
            deleteBeg();

        else if (type == 2)
            deleteEnd();

        else if (type == 3) {
            printf("Enter position: ");
            scanf("%d", &pos);
            deletePos(pos);
        }
    }

    printf("\nUpdated List: ");
    display();

    return 0;
}