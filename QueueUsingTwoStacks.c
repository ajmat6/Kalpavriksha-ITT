
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

void dequeue(Stack* st1, Stack* st2) {
    if(!isEmpty(st2)) pop(st2); // previous time we inserted from st1 to st2 so in st2 we still have nos in queue form
    else {
        while(!isEmpty(st1)) { 
            push(st2, peek(st1));
            pop(st1);
        }
        pop(st2);
    }
}

int queueFront(Stack* st1, Stack* st2) {
    if(!isEmpty(st2)) return peek(st2);
    while(!isEmpty(st1)) { 
        push(st2, peek(st1));
        pop(st1);
    }
    return peek(st2);
}

void result(int totalOps) {
    Stack st1, st2;
    initialize(&st1);
    initialize(&st2);
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
        else if(command == 2) dequeue(&st1, &st2);
        else if(command == 3) printf("Front element is %d\n", queueFront(&st1, &st2));
        else if(command == 4) {
            if(isEmpty(&st1) && isEmpty(&st2)) printf("Queue is empty\n");
            else printf("Queue is not empty\n");
        }
        else if(command == 5) printf("Queue size is %d\n", giveSize(&st1) + giveSize(&st2));
    }
}

int main() {
    int totalOps;
    printf("Enter total Operations: ");
    scanf("%d", &totalOps);
    result(totalOps);
    return 0;
}
