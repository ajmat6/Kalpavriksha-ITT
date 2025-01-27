#include<stdio.h>
#include<limits.h>

void printArray(int* arr, int size) {
    for(int i=0; i<size; i++) printf("%d ", arr[i]);
}

void selectionSort(int* arr, int size) {
    int putIndex = 0;
    for(int i=0; i<size-1; i++) {
        int mini = INT_MAX; int minIndex = -1;
        for(int j=putIndex; j<size; j++) {
            if(arr[j] < mini) {
                mini = arr[j];
                minIndex = j;
            }
        }
        
        int temp = arr[putIndex];
        arr[putIndex] = arr[minIndex];
        arr[minIndex] = temp;
        putIndex++;
    }
    printArray(arr, size);
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    selectionSort(arr, n);
}