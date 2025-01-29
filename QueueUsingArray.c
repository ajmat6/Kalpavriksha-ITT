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
        printf("Queue is Full!...\n");
        return;
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
        printf("Queue is Empty!...\n");
        return;
    }

    if(q -> front == q -> rear) q -> front = q -> rear = -1;
    else if(q -> front == (SIZE - 1)) q ->  front = 0;
    else q -> front += 1;
    q -> size -= 1;
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!...\n");
        return -1;
    }
    return q -> items[q -> front];
}

int qSize(Queue* q) {
    return q -> size;
}

void result(int totalOps) {
    Queue q;
    initialize(&q);
    for(int i=0; i<totalOps; i++) {
        printf("Press 1 to Enqueue\n");
        printf("Press 2 to Dequeue\n");
        printf("Press 3 to get front element\n");
        printf("Press 4 to check if queue is empty\n");
        printf("Press 5 to get queue size\n");

        int command;
        scanf("%d", &command);

        if(command == 1) {
            int value;
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            push(&q, value);
        }
        else if(command == 2) pop(&q);
        else if(command == 3) printf("Front element is %d\n", peek(&q));
        else if(command == 4) {
            if(isEmpty(&q)) printf("Queue is empty\n");
            else printf("Queue is not empty\n");
        }
        else if(command == 5) printf("Queue size is %d\n", qSize(&q));
    }
}

int main() {
    int totalOps;
    printf("Enter total Operations: ");
    scanf("%d", &totalOps);
    result(totalOps);
    return 0;
}