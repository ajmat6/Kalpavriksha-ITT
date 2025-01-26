#include<stdio.h>
#include<limits.h>

void printArray(int* arr, int size) {
    for(int i=0; i<size; i++) printf("%d ", arr[i]);
}

void binarySearch(int* arr, int size, int target) {
    int low = 0;
    int high = size - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) {
            printf("Element %d found at %d index!", target, mid);
            return;
        }
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    printf("Element %d is not found!", target);
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n]; // assuming array is sorted
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);

    int element;
    printf("Enter element to search: ");
    scanf("%d", &element);
    binarySearch(arr, n, element);
}