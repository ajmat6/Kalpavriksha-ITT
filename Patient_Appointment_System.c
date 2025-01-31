#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// enum for patient conditions:
enum conditions {
    CRITICAL, 
    SERIOUS,
    STABLE
};

// enum map function:
int getConditionEnum(char* condition) {
    if(strcmp(condition, "Critical") == 0) return CRITICAL;
    if(strcmp(condition, "Serious") == 0) return SERIOUS;
    if(strcmp(condition, "Stable") == 0) return STABLE;
    return -1; 
}

typedef struct Node {
    int id;
    enum conditions condition;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

void insertNode(int currId, enum conditions currCondition) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = currId;
    newNode->condition = currCondition;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

Node* merge(Node* first, Node* second) {
    Node* dummyNode = (Node*)malloc(sizeof(Node));
    dummyNode->next = NULL;
    Node* temp = dummyNode;

    while (first && second) {
        if (first->condition <= second->condition) {
            temp->next = first;
            first = first->next;
        } else {
            temp->next = second;
            second = second->next;
        }
        temp = temp->next;
    }

    if (first) temp->next = first;
    if (second) temp->next = second;

    return dummyNode->next;
}

Node* mergeSort(Node* currHead) {
    if (currHead == NULL || currHead->next == NULL) return currHead;

    Node* slow = currHead;
    Node* fast = currHead->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = slow->next;
    slow->next = NULL;
    Node* first = mergeSort(currHead);
    Node* second = mergeSort(fast);
    return merge(first, second);
}

void printNodes() {
    Node* temp = head;
    while (temp) {
        char* conditionStr;
        switch (temp->condition) {
            case CRITICAL: conditionStr = "Critical"; break;
            case SERIOUS: conditionStr = "Serious"; break;
            case STABLE: conditionStr = "Stable"; break;
        }
        printf("%d %s\n", temp->id, conditionStr);
        temp = temp->next;
    }
}

int checkIdPrev(int* allId, int uId, int currId) {
    for (int i = 0; i < uId; i++) {
        if (allId[i] == currId) return 1;
    }
    return 0;
}

void result(int n) {
    int allIds[10000];
    int uniqueIds = 0;

    for (int i = 0; i < n; i++) {
        int id;
        char condition[10];
        scanf("%d %s", &id, condition);

        if (checkIdPrev(allIds, uniqueIds, id)) {
            printf("Patient with this ID already exists. Please enter a unique ID.\n");
            i--;
            continue;
        }

        int conditionEnum = getConditionEnum(condition);
        if (conditionEnum == -1) {
            printf("Invalid patient condition. Please enter a valid condition (Critical, Serious, Stable).\n");
            i--;
            continue;
        }

        insertNode(id, conditionEnum);
        allIds[uniqueIds++] = id;
    }

    printf("Before Sorting:\n");
    printNodes();

    head = mergeSort(head);
    printf("After Sorting:\n");
    printNodes();
}

int main() {
    int n;
    scanf("%d", &n);
    result(n);
    return 0;
}
