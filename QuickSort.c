#include<stdio.h>

int findPartitionIndex(int* nums, int size, int low, int high) {
    int pivot = nums[low];
    int start = low;
    int end = high;
    
    while(start < end) {
        while(start < high && nums[start] <= pivot) start++;
        while(end > low && nums[end] > pivot) end--;
        if(start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
        }
    }

    int temp = nums[low];
    nums[low] = nums[end];
    nums[end] = temp;
    return end;
}

void quickSort(int* nums, int size, int low, int high) {
    if(low < high) {
        int partitionIndex = findPartitionIndex(nums, size, low, high);
        quickSort(nums, size, low, partitionIndex - 1);
        quickSort(nums, size, partitionIndex + 1, high);
    }
}

void printArray(int* arr, int size) {
    for(int i=0; i<size; i++) printf("%d ", arr[i]);
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    quickSort(arr, n, 0, n - 1);
    printArray(arr, n);
}