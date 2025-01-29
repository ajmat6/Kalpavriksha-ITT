#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 1000

typedef struct {
    int pages;
    char name[100];
} PrintJob;


typedef struct {
    int front;
    int rear;
    int size;
    PrintJob items[SIZE];
} Queue;

void initialize(Queue *q) {
    q -> front = -1;
    q -> rear = -1;
    q -> size = 0;
    for(int i=0; i<SIZE; i++) q -> items[i].pages = 0; // initialize struct
}

int isEmpty(Queue* q) {
    return q -> front == -1;
}

int isFull(Queue* q) {
    if((q -> front == 0 && q -> rear == (SIZE - 1)) || (q -> rear == (q -> front - 1))) return 1;
    return 0;
}

void push(Queue* q, char docName[], int docPages) {
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
    q -> items[q -> rear].pages = docPages;
    strcpy(q -> items[q -> rear].name, docName);
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

PrintJob peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty! Terminating...\n");
        exit(1);
    }
    return q -> items[q -> front];
}

int qSize(Queue* q) {
    return q -> size;
}

void pendingJobs(Queue* q) {
    if(q -> size == 0) {
        printf("No Pending Jobs\n");
        return;
    }

    Queue temp;
    initialize(&temp);

    while(!isEmpty(q)) {
        printf("Document Name: %s, Pages: %d\n", peek(q).name, peek(q).pages);
        push(&temp, peek(q).name, peek(q).pages);
        pop(q);
    }

    Queue temp2 = *q;
    *q = temp;
    temp = temp2;
}

void updateJob(Queue* q, char* oldDocName) {
    Queue temp;
    initialize(&temp);

    while(!isEmpty(q)) {
        if(strcmp(peek(q).name, oldDocName) == 0) {
            char newDocName[100];
            printf("Enter new Name: ");
            fgets(newDocName, sizeof(newDocName), stdin);
            if(newDocName[strlen(newDocName) - 1] == '\n') newDocName[strlen(newDocName) - 1] = '\0';

            int newJobPages;
            printf("Enter new Pages: ");
            scanf("%d", &newJobPages);
            getchar();
            push(&temp, newDocName, newJobPages);
        }
        else push(&temp, peek(q).name, peek(q).pages);
        pop(q);
    }

    Queue temp2 = *q;
    *q = temp;
    temp = temp2;
}

void cancelJob(Queue* q, char* docName) {
    Queue temp;
    initialize(&temp);

    while(!isEmpty(q)) {
        if(strcmp(peek(q).name, docName) != 0) push(&temp, peek(q).name, peek(q).pages);
        pop(q);
    }

    Queue temp2 = *q;
    *q = temp;
    temp = temp2;
}

void result(int totalOps) {
    Queue q;
    initialize(&q);
    for(int i=0; i<totalOps; i++) {
        printf("Press 1 to Add a Print Job\n");
        printf("Press 2 to View Pending Jobs\n");
        printf("Press 3 to edit a specific Job\n");
        printf("Press 4 to process a Job (Pop)\n");
        printf("Press 5 to Cancel a Specific Job from Queue\n");

        int command;
        scanf("%d", &command);
        getchar();

        if(command == 1) {
            char newJobDocName[100];
            printf("Enter new Job Document Name: ");
            fgets(newJobDocName, sizeof(newJobDocName), stdin);
            if(newJobDocName[strlen(newJobDocName) - 1] == '\n') newJobDocName[strlen(newJobDocName) - 1] = '\0';

            int newJobPages;
            printf("Enter new Job Document Pages: ");
            scanf("%d", &newJobPages);
            getchar();
            push(&q, newJobDocName, newJobPages);
        }
        else if(command == 2) pendingJobs(&q);
        else if(command == 3) {
            char oldDocName[100];
            printf("Enter Old Document Name to Update: ");
            fgets(oldDocName, sizeof(oldDocName), stdin);
            if(oldDocName[strlen(oldDocName) - 1] == '\n') oldDocName[strlen(oldDocName) - 1] = '\0';
            updateJob(&q, oldDocName);
        }
        else if(command == 4) pop(&q);
        else if(command == 5) {
            char cancelDocName[100];
            printf("Enter Document Name which you want to cancel: ");
            fgets(cancelDocName, sizeof(cancelDocName), stdin);
            if(cancelDocName[strlen(cancelDocName) - 1] == '\n') cancelDocName[strlen(cancelDocName) - 1] = '\0';
            cancelJob(&q, cancelDocName);
        }
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