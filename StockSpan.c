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

void result(int* nums, int size) {
    Stack st;
    initialize(&st);
    for(int i=0; i<size; i++) {
        while(isEmpty(&st) == 0 && nums[i] >= nums[peek(&st)]) pop(&st);
        int prevIndex = -1;
        if(isEmpty(&st) == 0) prevIndex = peek(&st);
        printf("%d ", i - prevIndex);
        push(&st, i);
    }
}

int main() {
    int size;
    scanf("%d", &size);

    int* nums = (int*)malloc(size * sizeof(int));
    for(int i=0; i<size; i++) scanf("%d", &nums[i]);
    result(nums, size);
    return 0;
}