#include<stdio.h>

void merge(int* nums, int size, int low, int mid, int high) {
    int temp[size];
    int tempIndex = 0;
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high) {
        if(nums[left] <= nums[right]) {
            temp[tempIndex++] = nums[left];
            left++;
        }
        else {
            temp[tempIndex++] = nums[right];
            right++;
        }
    }

    while(left <= mid) {
        temp[tempIndex++] = nums[left];
        left++;
    }

    while(right <= high) {
        temp[tempIndex++] = nums[right];
        right++;
    }

    for(int i=low; i<=high; i++) {
        nums[i] = temp[i - low];
    }
}

void mergeSort(int* nums, int size, int low, int high) {
    if(low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(nums, size, low, mid);
        mergeSort(nums, size, mid + 1, high);
        merge(nums, size, low, mid, high);
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
    mergeSort(arr, n, 0, n - 1);
    printArray(arr, n);
}