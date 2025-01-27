#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 1000

typedef struct {
    int top;
    char items[SIZE][SIZE];
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

void push(Stack* s, char ch[]) {
    if (isFull(s)) {
        printf("Stack is Full!\n");
        exit(1);
    }
    strcpy(s -> items[++(s -> top)], ch);
}

void pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    s -> items[(s -> top)--];
}

char* peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is Empty!\n");
        exit(1);
    }
    return s -> items[s -> top];
}

int isOperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^') return 1;
    return 0;
}

void result(char* input) {
    Stack st;
    initialize(&st);
    int size = strlen(input);
    for(int i=size - 1; i>=0; i--) {
        if(!isOperator(input[i])) {
            char currString[2];
            currString[0] = input[i];
            currString[1] = '\0';
            push(&st, currString);
        }

        else {
            char resultant[1000];
            char operator = input[i];
            char* first = peek(&st); pop(&st);
            char* second = peek(&st); pop(&st);

            int index = 1;
            resultant[0] = '(';
            for(int i=0; first[i] != '\0'; i++) resultant[index++] = first[i];
            resultant[index++] = operator;
            for(int i=0; second[i] != '\0'; i++) resultant[index++] = second[i];
            resultant[index++] = ')';
            
            resultant[index] = '\0';
            push(&st, resultant);
        }
    }
    printf("%s", peek(&st));
}

int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);
    if(input[strlen(input) - 1] == '\n') input[strlen(input) - 1] = '\0';
    result(input);
    return 0;
}