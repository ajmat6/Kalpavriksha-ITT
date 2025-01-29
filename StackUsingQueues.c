#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 1000

typedef struct {
    int front;
    int rear;
    int size;
    int items[SIZE];
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

void push(Queue* q, int value) {
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
    q -> items[q -> rear] = value;
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

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty! Terminating...\n");
        exit(1);
    }
    return q -> items[q -> front];
}

int qSize(Queue* q) {
    return q -> size;
}

void stackPush(Queue* q, int value) {
    push(q, value);
    int qSize = q -> size;
    for(int i=0; i<(qSize - 1); i++) {
        int qFront = peek(q);
        push(q, qFront);
        pop(q);
    }
}

void stackPop(Queue* q) {
    pop(q);
}

int stackPeek(Queue* q) {
    return peek(q);
}

void stackDisplay(Queue* q) {
    if(isEmpty(q)) {
        printf("No elements to display!\n");
        return;
    }

    printf("Elements from top of stack to bottom are: ");
    int frontIndex = q -> front;
    int rearIndex = q -> rear;
    if(rearIndex < frontIndex) {
        for(int i=frontIndex; i<SIZE; i++) printf("%d ", q -> items[i]);
        for(int i=0; i<=rearIndex; i++) printf("%d ", q -> items[i]);
    }
    else {
        for(int i=frontIndex; i<=rearIndex; i++) printf("%d ", q -> items[i]);
    }
    printf("\n");
}

void result(int totalOperations) {
    Queue q;
    initialize(&q);
    for(int i=0; i<totalOperations; i++) {
        printf("Press 1 to push\n");
        printf("Press 2 to pop\n");
        printf("Press 3 to get peek element\n");
        printf("Press 4 to display all stack elements\n");

        int command;
        scanf("%d", &command);

        if(command == 1) {
            int value;
            printf("Enter value to push into stack: ");
            scanf("%d", &value);
            stackPush(&q, value);
        }
        else if(command == 2) stackPop(&q);
        else if(command == 3) printf("%d\n", stackPeek(&q));
        else if(command == 4) stackDisplay(&q);
        else printf("Invalid Command!\n");
    }
}

int main() {
    int totalOperations;
    printf("Enter total Number of Operations: ");
    scanf("%d", &totalOperations);
    result(totalOperations);
    return 0;
}