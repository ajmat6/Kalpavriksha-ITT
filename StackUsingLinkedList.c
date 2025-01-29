#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 1000


typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
int size = 0;

void insertAtBeginning(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode ->  data = value;
    newNode -> next = head;
    head = newNode;
}

int isEmpty() {
    return head == NULL;
}

int giveSize() {
    return size;
}

void push(int value) {
    insertAtBeginning(value);
    size += 1;
}

void pop() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return;
    }
    head = head -> next;
    size -= 1;
}

void peek() {
    if (isEmpty()) {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Peek element is %d\n", head -> data);
}

void result(int totalOps) {
    for(int i=0; i<totalOps; i++) {
        printf("Press 1 to push\n");
        printf("Press 2 to pop\n");
        printf("Press 3 to get peek element\n");
        printf("Press 4 to check if stack is empty\n");
        printf("Press 5 to get stack size\n");

        int command;
        scanf("%d", &command);

        if(command == 1) {
            int value;
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
        }
        else if(command == 2) pop();
        else if(command == 3) peek();
        else if(command == 4) {
            if(isEmpty()) printf("Stack is empty\n");
            else printf("Stack is not empty\n");
        }
        else if(command == 5) printf("Stack size is %d\n", giveSize());
    }
}

int main() {
    int totalOps;
    printf("Enter total Operations: ");
    scanf("%d", &totalOps);
    result(totalOps);
    return 0;
}