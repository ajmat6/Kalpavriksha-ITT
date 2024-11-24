#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // considering string size to be 100 at max


// stack implement:
typedef struct {
    int top;
    int items[MAX];
} Stack;

void initialize(Stack *s) {
    s -> top = -1;
}

int isEmpty(Stack* s) {
    return s -> top == -1;
}

int isFull(Stack* s) {
    return s -> top == MAX - 1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Invalid expression\n");
        exit(1);
    }
    s -> items[++(s -> top)] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Invalid expression\n");
        exit(1);
    }
    return s -> items[(s -> top)--];
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Invalid expression\n");
        exit(1);
    }
    return s->items[s->top];
}


// operator check:
int isOperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/') return 1;
    return 0;
}

// digit check:
int isDigit(char ch)  {
    if(ch >= '0' && ch <= '9') return 1;
    return 0;
}

// precedence find:
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    else if(op == '*' || op == '/') return 2;
    return 0;
}

// operation apply:
int applyOperation(int a, int b, char op) {
    if(op == '+') return a + b;
    else if(op == '-') return a - b;
    else if(op == '*') return a * b;
    else if(op == '/') {
        if (b == 0) {
            printf("Error: Division by zero\n");
            exit(1);
        }
        return a / b;
    }
    else {
        printf("Error: Invalid expression\n");
        exit(1);
    }
}

// main evaluation function: I am considering that if '(' and ')' are in string than it is invalid exp as given in question:
int result(char *exp) {
    Stack values, ops;
    initialize(&values);
    initialize(&ops);

    int i = 0;
    while (exp[i] != '\0') {
        if (isDigit(exp[i]) || (exp[i] == '-' && isDigit(exp[i + 1]) && (i == 0 || !isDigit(exp[i - 1])))) { // *- or /- together case, ,will ignore 4-5 case when both sides have digits
            int value = 0;
            int sign = 1;

            if (exp[i] == '-') {
                sign = -1;
                i++;
            }

            while (i < strlen(exp) && isDigit(exp[i])) {
                value = (value * 10) + (exp[i] - '0');
                i++;
            }
            push(&values, value * sign);
        } 

        else if (isOperator(exp[i])) {
            while (!isEmpty(&ops) && precedence(peek(&ops)) >= precedence(exp[i])) {
                int val2 = pop(&values);
                int val1 = pop(&values);
                char op = pop(&ops);
                push(&values, applyOperation(val1, val2, op));
            }
            push(&ops, exp[i]);
            i++;
        } 

        else {
            printf("Error: Invalid expression.\n");
            exit(1);
        }
    }

    while (!isEmpty(&ops)) {
        int val2 = pop(&values);
        int val1 = pop(&values);
        char op = pop(&ops);
        push(&values, applyOperation(val1, val2, op));
    }

    if (!isEmpty(&ops) || values.top > 0) { // more than one value in value stack:
        printf("Error: Invalid expression.\n");
        exit(1);
    }

    return pop(&values);
}

int main() {
    char exp[MAX];

    printf("Enter an expression: ");
    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = '\0';

    // remove spaces:
    int i = 0;
    int tempIndex = 0;
    while(exp[i] != '\0') {
        if(exp[i] != ' ') {
            exp[tempIndex] = exp[i];
            tempIndex++;
        }
        i++;
    }
    exp[tempIndex] = '\0';
    
    printf("Result is : %d\n", result(exp));
    return 0;
}