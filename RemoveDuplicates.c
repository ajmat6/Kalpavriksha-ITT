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

void deleteNodes() {
    Node* temp = head;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    int currValue = head -> data;
    Node* currNode = head;
    while(temp) {
        while(temp && temp -> data == currValue) {
            temp = temp -> next;
        }
        currNode -> next = temp;
        currNode = temp;
        if(temp) currValue = temp -> data;
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
    // printNodes();
    deleteNodes();
    // printf("\n");
    printNodes();
}