#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;
int size = 0;

void insertAtEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode ->  data = value;
    newNode -> next = NULL;
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail -> next = newNode;
        tail = tail -> next;
    }
}

int isEmpty() {
    return head == NULL;
}

int giveSize() {
    return size;
}

void push(int value) {
    insertAtEnd(value);
    size += 1;
}

void pop() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    Node* temp = head;
    head = head -> next;
    if(head == NULL) tail = NULL;
    free(temp);
    size -= 1;
}

void peek() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Front element is %d\n", head -> data);
}

void result(int totalOps) {
    for(int i=0; i<totalOps; i++) {
        printf("Press 1 to Enqueue\n");
        printf("Press 2 to Dequeue\n");
        printf("Press 3 to get front element\n");
        printf("Press 4 to check if queue is empty\n");
        printf("Press 5 to get queue size\n");

        int command;
        scanf("%d", &command);

        if(command == 1) {
            int value;
            printf("Enter value to Enqueue: ");
            scanf("%d", &value);
            push(value);
        }
        else if(command == 2) pop();
        else if(command == 3) peek();
        else if(command == 4) {
            if(isEmpty()) printf("Queue is empty\n");
            else printf("Queue is not empty\n");
        }
        else if(command == 5) printf("Queue size is %d\n", giveSize());
    }
}

int main() {
    int totalOps;
    printf("Enter total Operations: ");
    scanf("%d", &totalOps);
    result(totalOps);
    return 0;
}