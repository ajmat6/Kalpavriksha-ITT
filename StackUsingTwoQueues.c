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

void stackPush(Queue* q1, Queue* q2, int value) {
    push(q2, value);
    while(!isEmpty(q1)) {
        push(q2, peek(q1));
        pop(q1);
    }

    // swapping of queues:
    Queue temp = *q1;
    *q1 = *q2;
    *q2 = temp;
}

void stackPop(Queue* q) {
    pop(q);
}

int stackPeek(Queue* q) {
    return peek(q);
}

void result(int totalOperations) {
    Queue q1, q2;
    initialize(&q1);
    initialize(&q2);
    for(int i=0; i<totalOperations; i++) {
        printf("Press 1 to push\n");
        printf("Press 2 to pop\n");
        printf("Press 3 to get peek element\n");
        printf("Press 4 to check if stack is empty or not\n");
        printf("Press 5 to get stack size\n");

        int command;
        scanf("%d", &command);

        if(command == 1) {
            int value;
            printf("Enter value to push into stack: ");
            scanf("%d", &value);
            stackPush(&q1, &q2, value);
        }
        else if(command == 2) stackPop(&q1);
        else if(command == 3) printf("Peek element in stack is %d\n", stackPeek(&q1));
        else if(command == 4) {
            if(isEmpty(&q1)) printf("Stack is empty\n");
            else printf("Stack is not empty\n");
        }
        else if(command == 5) printf("Size of the stack is %d\n", qSize(&q1));
    }
}

int main() {
    int totalOperations;
    printf("Enter total Number of Operations: ");
    scanf("%d", &totalOperations);
    result(totalOperations);
    return 0;
}