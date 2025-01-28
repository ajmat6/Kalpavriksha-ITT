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

void dequeue(Stack* st1) {
    if(giveSize(st1) == 0) {
        printf("Queue is Empty\n");
        return;
    }

    if(giveSize(st1) == 1) {
        pop(st1);
        return;
    }

    int topElement = peek(st1);
    pop(st1);
    dequeue(st1);
    push(st1, topElement);
}

void queueFront(Stack* st1) {
    if(giveSize(st1) == 0) {
        printf("Queue is Empty\n");
        return;
    }

    if(giveSize(st1) == 1) {
        printf("Front element of queue is %d\n", peek(st1));
        return;
    }

    int topElement = peek(st1);
    pop(st1);
    queueFront(st1);
    push(st1, topElement);
}

void result(int totalOps) {
    Stack st1;
    initialize(&st1);
    for(int i=0; i<totalOps; i++) {
        printf("Press 1 to Enqueue\n");
        printf("Press 2 to Dequeue\n");
        printf("Press 3 to get front element\n");
        printf("Press 4 to check if Queue is empty\n");
        printf("Press 5 to get Queue size\n");

        int command;
        scanf("%d", &command);

        if(command == 1) {
            int value;
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&st1, value);
        }
        else if(command == 2) dequeue(&st1);
        else if(command == 3) queueFront(&st1);
        else if(command == 4) {
            if(isEmpty(&st1)) printf("Queue is empty\n");
            else printf("Queue is not empty\n");
        }
        else if(command == 5) printf("Queue size is %d\n", giveSize(&st1));
    }
}

int main() {
    int totalOps;
    printf("Enter total Operations: ");
    scanf("%d", &totalOps);
    result(totalOps);
    return 0;
}