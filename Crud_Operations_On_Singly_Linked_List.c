#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void insertAtBeginning(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode ->  data = value;
    newNode -> next = head;
    head = newNode;
}

void insertAtEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = NULL;
    if(head == NULL) head = newNode;
    else {
        Node* temp = head;
        while(temp -> next != NULL) temp = temp -> next;
        temp -> next = newNode;
    }
}

void insertAtPosition(int position, int value) {
    if(position == 1) {
        insertAtBeginning(value);
        return;
    }

    int currPos = 1;
    Node* currNode = head;
    while(currPos < position - 1) {
        currNode = currNode -> next;
        currPos++;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> next = currNode -> next;
    currNode -> next = newNode;
}

void display() {
    Node* temp = head;
    printf("All Nodes are: ");
    while(temp) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

void updateAtPosition(int position, int newValue) {
    int currPos = 1;
    Node* currNode = head;
    while(currPos < position) {
        currNode = currNode -> next;
        currPos++;
    }

    currNode -> data = newValue;
}

void deleteAtBeginning() {
    Node* temp = head;
    head = head -> next;
    temp -> next = NULL;
    free(temp);
}

void deleteAtEnd() {
    Node* prev = NULL;
    Node* curr = head;
    while(curr -> next) {
        prev = curr;
        curr = curr -> next;
    }

    if(prev == NULL) head = NULL;
    else prev -> next = NULL;
    free(curr);
}

void deleteAtPosition(int position) {
    if(position == 1) {
        deleteAtBeginning();
        return;
    }

    int currPos = 1;
    Node* prev = NULL;
    Node* curr = head;
    while(currPos < position) {
        prev = curr;
        curr = curr -> next;
    }

    prev -> next = curr -> next;
    curr -> next = NULL;
    free(curr);
}

void handleOperations(int n) {
    int totalNodes = 0;
    for(int i=0; i<n; i++) {
        printf("Available Operations:\n");
        printf("Enter 1 to add node at end\n");
        printf("Enter 2 to add node at start\n");
        printf("Enter 3 to add node at a position\n");
        printf("Enter 4 to display all nodes\n");
        printf("Enter 5 to update node value at a given position\n");
        printf("Enter 6 to delete node at start\n");
        printf("Enter 7 to delete node at end\n");
        printf("Enter 8 to delete node at a given position\n");

        int option;
        scanf("%d", &option);

        if(option <= 0 || option > 8) {
            printf("Invalid option! Please press correct option..\n");
            i--;
        }
        else if(option == 1 || option == 2) {
            int value;
            printf("Enter new node value: ");
            scanf("%d", &value);
            if(option == 1) insertAtBeginning(value);
            else insertAtEnd(value);
            totalNodes++;
        }
        else if(option == 3) {
            printf("Enter position and value of new node: ");
            int position, value;
            scanf("%d%d", &position, &value);
            if(position <= 0 || position > totalNodes + 1) printf("Invalid position\n");
            else {
                insertAtPosition(position, value);
                totalNodes++;
            }
        }
        else if(option == 4) {
            if(totalNodes == 0) printf("No nodes to print!\n");
            else display();
        }
        else if(option == 5) {
            int position, newValue;
            printf("Enter position and new value of node to update: ");
            scanf("%d%d", &position, &newValue);
            if(position <= 0 || position > totalNodes) printf("Invalid position\n");
            else updateAtPosition(position, newValue);
        }
        else if(option == 6 || option == 7) {
            if(totalNodes == 0) printf("No nodes to delete\n");
            else if(option == 6) {
                deleteAtBeginning();
                printf("Node at beginning deleted!\n");
            }
            else {
                deleteAtEnd();
                printf("Node at end deleted!\n");
            }
        }
        else {
            int position;
            printf("Enter position to delete: ");
            scanf("%d", &position);
            if(position <= 0 || position > totalNodes) printf("Invalid position\n");
            else deleteAtPosition(position);
        }
    }
}

int main() {
    int n;
    printf("Enter number of operations: ");
    scanf("%d", &n);
    handleOperations(n);
    return 0;   
}