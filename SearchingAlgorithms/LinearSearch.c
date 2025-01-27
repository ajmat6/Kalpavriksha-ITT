#include<stdio.h>
#include<limits.h>

void printArray(int* arr, int size) {
    for(int i=0; i<size; i++) printf("%d ", arr[i]);
}

void linearSearch(int* arr, int size, int target) {
    for(int i=0; i<size; i++) {
        if(arr[i] == target) {
            printf("Element %d found at %d index!", target, i);
            return;
        }
    }
    printf("Element %d is not found!", target);
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);

    int element;
    printf("Enter element to search: ");
    scanf("%d", &element);
    linearSearch(arr, n, element);
}