#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];
void initialize() {
    for(int i=0; i<TABLE_SIZE; i++) hashTable[i] = NULL;
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void deleteKey(int currKey) {
    int index = hashFunction(currKey);
    if(hashTable[index] == NULL) {
        printf("Key not found to delete\n");
        return;
    }

    Node* temp = hashTable[index];
    Node* prev = NULL;
    while(temp && temp -> key != currKey) {
        prev = temp;
        temp = temp -> next;
    }

    if(temp == NULL) {
        printf("Key not found to delete\n");
        return;
    }
    else if(prev == NULL) hashTable[index] = temp -> next;
    else prev -> next = temp -> next;
    free(temp);
    printf("Key %d deleted\n", currKey);
}

void insert(int key, int value) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Insertion of data failed!\n");
        return;
    }

    deleteKey(key); // prev existence

    newNode -> key = key;
    newNode -> value = value;
    newNode -> next = hashTable[index];
    hashTable[index] = newNode;
}

Node* search(int currKey) {
    int index = hashFunction(currKey);
    Node* temp = hashTable[index];
    while(temp && temp -> key != currKey) temp = temp -> next;
    return temp;
}

void printTable() {
    printf("Hash Table:\n");
    for(int i=0; i<TABLE_SIZE; i++) {
        if(hashTable[i] != NULL) {
            Node* temp = hashTable[i];
            printf("Index %d:\t", i);
            while(temp) {
                printf("{%d, %d} -> ", temp -> key, temp -> value);
                temp = temp -> next;
            }
            printf("NULL\n");
        }
        else printf("Index %d:\tNULL\n", i);
    }
}

void result() {
    initialize();
    while(1) {
        printf("Press 1 to insert key value pair\n");
        printf("Press 2 to check existence of key value pair(search)\n");
        printf("Press 3 to delete a key value pair\n");
        printf("Press 4 to print hash table\n");
        printf("Print 5 to terminate the program\n");

        int command;
        scanf("%d", &command);
        getchar();

        if(command == 1) {
            int key, value;
            printf("Enter key value pair: ");
            scanf("%d%d", &key, &value);
            insert(key, value);
        }
        else if(command == 2) {
            int key;
            printf("Enter key to check: ");
            scanf("%d", &key);
            Node* res = search(key);
            if(res == NULL) printf("Key %d does not exist\n", key);
            else printf("Key %d exist with value %d\n", key, res -> value);
        }
        else if(command == 3) {
            int key;
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteKey(key);
        }
        else if(command == 4) printTable();
        else if(command == 5) exit(0);
        else printf("Invalid command\n");
    }
}

int main() {
    result();
    return 0;
}