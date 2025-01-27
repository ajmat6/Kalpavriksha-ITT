#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 1000

typedef struct {
    int top;
    char items[SIZE];
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

void push(Stack* s, char ch) {
    if (isFull(s)) {
        printf("Stack is Full!\n");
        exit(1);
    }
    s -> items[++(s -> top)] = ch;
}

void pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    s -> items[(s -> top)--];
}

char peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is Empty!\n");
        exit(1);
    }
    return s -> items[s -> top];
}

void result(char* input) {
    int size = strlen(input);
    Stack st;
    initialize(&st);
    for(int i=0; input[i] != '\0'; i++) {
        if(input[i] == '[' || input[i] == '{' || input[i] == '(') push(&st, input[i]);
        else {
            if(isEmpty(&st) || (input[i] == ')' && peek(&st) != '(') || (input[i] == '}' && peek(&st) != '{') || (input[i] == ']' && peek(&st) != '[')) {
                printf("false\n");
                return;
            }
            pop(&st);
        }
    }
    if(isEmpty(&st)) printf("true");
    else printf("false");
}

int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);
    if(input[strlen(input) - 1] == '\n') input[strlen(input) - 1] = '\0';
    result(input);
    return 0;
}