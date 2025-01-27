#include<stdio.h>

void printArray(int* arr, int size) {
    for(int i=0; i<size; i++) printf("%d ", arr[i]);
}

void insertionSort(int* arr, int size) {
    for(int i=1; i<size; i++) {
        int curr = i;
        int val = arr[curr]; 
        while(curr > 0 && val < arr[curr - 1]) {
            arr[curr] = arr[curr - 1];
            curr--;
        }
        arr[curr] = val;
    }
    printArray(arr, size);
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    insertionSort(arr, n);
}