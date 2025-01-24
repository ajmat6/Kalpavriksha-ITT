#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void insertNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail -> next = newNode;
        tail = newNode;
    }
}

void printNodes() {
    Node* temp = head;
    while(temp) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
}

void rotateNodes(int k) {
    if(head == NULL) return;
    if(head -> next == NULL) return;

    Node* temp = head;
    int len = 0;
    while(temp -> next != NULL) {
        temp = temp -> next; // reaching tail
        len++;
    }
    len++;

    k = k % len;

    while(k) {
        Node* headNode = head;
        Node* nextNode = head -> next;
        headNode -> next = NULL;
        head = nextNode;
        temp -> next = headNode;
        temp = temp -> next;
        k--;
    }
}

int main() {
    int n;
    printf("Enter no of nodes: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        int nodeValue;
        scanf("%d", &nodeValue);
        insertNode(nodeValue);
    }

    int k;
    printf("Enter k Value: ");
    scanf("%d", &k);
    rotateNodes(k);
    printNodes();
}