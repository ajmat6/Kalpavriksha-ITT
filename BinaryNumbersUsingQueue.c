#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 1000

typedef struct {
    int front;
    int rear;
    int size;
    char items[SIZE][SIZE];
} Queue;

void initialize(Queue *q) {
    q -> front = -1;
    q -> rear = -1;
    q -> size = 0;
}

int isEmpty(Queue* q) {
    return q -> front == -1;
}

int isFull(Queue* q) {
    if((q -> front == 0 && q -> rear == (SIZE - 1)) || (q -> rear == (q -> front - 1))) return 1;
    return 0;
}

void push(Queue* q, char ch[]) {
    if (isFull(q)) {
        printf("Queue is Full! Terminating...\n");
        exit(1);
    }

    if(q -> front == -1) {
        q -> front = 0;
        q -> rear = 0;
    }
    else if(q -> rear == SIZE - 1 && q -> front != 0) q -> rear = 0;
    else q -> rear += 1;
    strcpy(q -> items[q -> rear], ch);
    q -> size += 1;
}

void pop(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty! Terminating...\n");
        exit(1);
    }

    if(q -> front == q -> rear) q -> front = q -> rear = -1;
    else if(q -> front == (SIZE - 1)) q ->  front = 0;
    else q -> front += 1;
    q -> size -= 1;
}

char* peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty! Terminating...\n");
        exit(1);
    }
    return q -> items[q -> front];
}

int qSize(Queue* q) {
    return q -> size;
}

void result(int N) {
    Queue q;
    initialize(&q);
    char* curr = "1";
    push(&q, curr);

    while(N--) {
        char* frontElement = peek(&q); pop(&q);
        printf("%s ", frontElement);
        char next1[32], next2[32];
        strcpy(next1, frontElement);
        strcpy(next2, frontElement);
        strcat(next1, "0");
        strcat(next2, "1");
        push(&q, next1); push(&q, next2);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    result(N);
    return 0;
}