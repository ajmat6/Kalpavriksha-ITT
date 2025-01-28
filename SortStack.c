#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 1000

typedef struct {
    int top;
    int items[SIZE];
} Stack;

void initialize(Stack *s) {
    s -> top = -1;
}

int isEmpty(Stack* s) {
    return s -> top == -1;
}

int isFull(Stack* s) {
    return s -> top == SIZE - 1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack is Full!\n");
        exit(1);
    }
    s -> items[++(s -> top)] = value;
}

void pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    s -> top -= 1;
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is Empty!\n");
        exit(1);
    }
    return s -> items[s -> top];
}

void result(int size) {
    Stack st;
    initialize(&st);
    for(int i=0; i<size; i++) {
        int num;
        scanf("%d", &num);
        push(&st, num);
    }

    Stack temp;
    initialize(&temp);
    while(!isEmpty(&st)) {
        int currElement = peek(&st); pop(&st);
        while(!isEmpty(&temp) && peek(&temp) < currElement) {
            push(&st, peek(&temp));
            pop(&temp);
        }
        push(&temp, currElement);
    }

    while(!isEmpty(&temp)) {
        printf("%d ", peek(&temp));
        pop(&temp);
    }
}

int main() {
    int size;
    scanf("%d", &size);
    result(size);
    return 0;
}