#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
    int top;
    int size;
    char** items;
} Stack;

void initialize(Stack *s, int n) {
    s -> top = -1;
    s -> size = n;
    s -> items = (char**)malloc(n * sizeof(char*));
}

int isEmpty(Stack* s) {
    return s -> top == -1;
}

int isFull(Stack* s) {
    return s -> top == (s -> size) - 1;
}

void push(Stack* s, char ch[]) {
    if (isFull(s)) {
        printf("Stack is Full!\n");
        exit(1);
    }
    
    s -> items[++(s -> top)] = (char*)malloc((strlen(ch) + 1) * sizeof(char));
    strcpy(s -> items[s -> top], ch);
}

void pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1);
    }
    free(s -> items[(s -> top)--]);
}

char* peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is Empty!\n");
        exit(1);
    }
    return s -> items[s -> top];
}

int giveSize(Stack* s) {
    return s -> size;
}

void history(Stack* s) {
    if(s -> top == -1) {
        printf("No History Found!\n");
        return;
    }

    Stack temp;
    initialize(&temp, giveSize(s));

    printf("History of the websites visited is:\n");
    while(!isEmpty(s)) {
        printf("%s\n", peek(s));
        push(&temp, peek(s));
        pop(s);
    }

    while(!isEmpty(&temp)) {
        push(s, peek(&temp));
        pop(&temp);
    }
}

void clearHistory(Stack* s) {
    while(!isEmpty(s)) pop(s);
    if(isEmpty(s)) printf("History cleaned!\n");
}

void updateURL(Stack* s, char* oldURL, char* newURL) {
    Stack temp;
    initialize(&temp, giveSize(s));
    int isFound = 0;
    while(!isEmpty(s)) {
        if(strcmp(peek(s), oldURL) == 0) {
            push(&temp, newURL);
            isFound = 1;
        }
        else push(&temp, peek(s));
        pop(s);
    }

    while(!isEmpty(&temp)) {
        push(s, peek(&temp));
        pop(&temp);
    }

    if(isFound) printf("%s URL is updated with %s URL\n", oldURL, newURL);
    else printf("New %s URL found to update\n", oldURL);
}

void result(int totalOps) {
    Stack st;
    initialize(&st, totalOps);
    for(int i=0; i<totalOps; i++) {
        printf("Press 1 to Add new URL\n");
        printf("Press 2 to Read History of visited Sites\n");
        printf("Press 3 to edit a specific URL\n");
        printf("Press 4 to remove recently visited website from the history\n");
        printf("Press 5 to clear history\n");
        printf("Press 6 to see recently visited website\n");

        int command;
        scanf("%d", &command);
        getchar();

        if(command == 1) {
            char newURL[100];
            printf("Enter new URL: ");
            fgets(newURL, sizeof(newURL), stdin);
            if(newURL[strlen(newURL) - 1] == '\n') newURL[strlen(newURL) - 1] = '\0';
            push(&st, newURL);
        }
        else if(command == 2) history(&st);
        else if(command == 3) {
            char oldURL[100];
            printf("Enter Old URL to Update: ");
            fgets(oldURL, sizeof(oldURL), stdin);
            if(oldURL[strlen(oldURL) - 1] == '\n') oldURL[strlen(oldURL) - 1] = '\0';

            char newURL[100];
            printf("Enter New URL to Replace Old URL: ");
            fgets(newURL, sizeof(newURL), stdin);
            if(newURL[strlen(newURL) - 1] == '\n') newURL[strlen(newURL) - 1] = '\0';
            updateURL(&st, oldURL, newURL);
        }
        else if(command == 4) pop(&st);
        else if(command == 5) clearHistory(&st);
        else if(command == 6) printf("Recently visited webiste is %s\n", peek(&st));
        else printf("Invalid option\n");
    }
}

int main() {
    int totalOps;
    printf("Enter total Operations: ");
    scanf("%d", &totalOps);
    getchar();
    result(totalOps);
    return 0;
}