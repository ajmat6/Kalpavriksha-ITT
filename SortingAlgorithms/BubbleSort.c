#include<stdio.h>

void printArray(int* arr, int size) {
    for(int i=0; i<size; i++) printf("%d ", arr[i]);
}

void bubbleSort(int* arr, int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-1-i; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printArray(arr, size);
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    bubbleSort(arr, n);
}