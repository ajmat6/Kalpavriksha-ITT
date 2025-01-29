#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 100

typedef struct {
    int top;
    int curr;
    char items[SIZE][SIZE];
} Stack;

void initialize(Stack *s) {
    s -> top = -1;
    s -> top = -1;
}

int isEmpty(Stack* s) {
    return s -> curr == -1;
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
        printf("No operation to perform for undo and redo!\n");
        exit(1);
    }
    s -> top -= 1;
}

char* peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is Empty!\n");
        exit(1);
    }
    return s -> items[s -> top];
}

void result(int totalOps) {
    Stack undo, redo;
    initialize(&undo);
    initialize(&redo);
    push(&undo, ""); // initial state
    for(int i=0; i<totalOps; i++) {
        printf("Press 1 to add new character\n");
        printf("Press 2 to perform Undo\n");
        printf("Press 3 to perform Redo Task\n");
        printf("Press 4 to see current state of string\n");

        int command;
        scanf("%d", &command);
        getchar();

        if(command == 1) {
            char ch;
            printf("Type new Character: ");
            scanf("%c", &ch);

            char temp[100];
            strcpy(temp, peek(&undo));
            temp[strlen(temp)] = ch;
            temp[strlen(temp)] = '\0';
            push(&undo, temp);
            initialize(&redo); // clean redo when latest character is typed (can't move forward);
        }
        else if(command == 2) {
            if(undo.top == -1) printf("No Undo operations to perform\n");
            else {
                push(&redo, peek(&undo));
                pop(&undo);
            }
        }
        else if(command == 3) {
            if(redo.top == -1) printf("No Redo operations to perform\n");
            else {
                push(&undo, peek(&redo));
                pop(&redo);
            }
        }
        else if(command == 4) printf("Current State of String is %s\n", peek(&undo));
        else printf("Invalid Command\n");
    } 
}

int main() {
    int totalOps;
    printf("Enter total Operations you will perform for undo and redo: ");
    scanf("%d", &totalOps);
    getchar();
    result(totalOps);
    return 0;
}