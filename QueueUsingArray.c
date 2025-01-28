#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 1000

typedef struct {
    int top;
    int size;
    int items[SIZE];
} Stack;

void initialize(Stack *s) {
    s -> top = -1;
    s -> size = 0;
}

int isFull(Stack* s) {
    return s -> top == SIZE - 1;
}

int isEmpty(Stack* s) {
    return s -> top == -1;
}

int giveSize(Stack* s) {
    return s -> size;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack is Full!\n");
        return;
    }
    s -> items[++(s -> top)] = value;
    s -> size += 1;
}

void pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    s -> top -= 1;
    s -> size -= 1;
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is Empty!\n");
        return -1;
    }
    return s -> items[s -> top];
}

void result(int totalOps) {
    Stack st;
    initialize(&st);
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
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&st, value);
        }
        else if(command == 2) pop(&st);
        else if(command == 3) printf("Peek element is %d\n", peek(&st));
        else if(command == 4) {
            if(isEmpty(&st)) printf("Stack is empty\n");
            else printf("Stack is not empty\n");
        }
        else if(command == 5) printf("Stack size is %d\n", giveSize(&st));
    }
}

int main() {
    int totalOps;
    printf("Enter total Operations: ");
    scanf("%d", &totalOps);
    result(totalOps);
    return 0;
}