// Given a linked list and a position nodePos. Romve nodePos node from the end of the Linked list. Don't modify the linked list to do so. Also sort the linked list in ascending order and print it.

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void insertNode(int dataue) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = dataue;
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
    printf("\n");
}

void removeNode(int n) {
    Node* slow = head;
    Node* fast = head;

    for(int i=0; i<n; i++) fast = fast -> next;

    if(fast == NULL) {
        head = head -> next;
        return;
    }

    while(fast -> next != NULL) {
        fast = fast -> next;
        slow = slow -> next;
    }
    slow -> next = slow -> next -> next;
}

Node* merge(Node* head1, Node* head2) {
    Node* dummyHead = (Node*)malloc(sizeof(Node));
    Node* temp = dummyHead;

    Node* first = head1; Node* second = head2;
    while(first && second) {
        if(first -> data <= second -> data) {
            temp -> next = first;
            first = first -> next;
        }
        else {
            temp -> next = second;
            second = second -> next;
        }
        temp = temp -> next;
    }

    while(first) {
        temp -> next = first;
        temp = temp -> next;
        first = first -> next;
    }

    while(second) {
        temp -> next = second;
        temp = temp -> next;
        second = second -> next;
    }

    return dummyHead -> next;
}

Node* mergeSort(Node* head) {
    if(!head || !head -> next) return head;

    // when there are 2 nodes:
    else if(head -> next -> next == NULL) {
        if(head -> data <= head -> next -> data) return head;
        Node* nextt = head -> next;
        nextt -> next = head;
        head -> next = NULL;
        return nextt;
    }

    // find the middle of linked List:
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    Node* midNext = slow -> next;
    slow -> next = NULL;
    Node* left = mergeSort(head);
    Node* right = mergeSort(midNext);
    return merge(left, right);
}

void sortList() {
    head = mergeSort(head);
    return;
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

    int nodePos;
    printf("Enter the position from which you want to remove the node from end: ");
    scanf("%d", &nodePos);
    if(nodePos <= 0 && nodePos > n) {
        printf("Enter valid node position\n");
        return 0;
    }

    removeNode(nodePos);
    printf("After removing node from %d position from end, Linked list is: ", nodePos);
    printNodes();
    sortList();
    printf("After sorting linked list is: ");
    printNodes();
}