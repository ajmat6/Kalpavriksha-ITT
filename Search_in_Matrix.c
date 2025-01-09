#include<stdio.h>

void result(int rows, int cols, int matrix[][cols], int target) {
    int low = 0;
    int high = cols - 1;

    while(low < rows && cols >= 0) {
        int currElement = matrix[low][high];
        if(currElement == target) {
            printf("Element %d found in the matrix at %d row and %d column.", target, low + 1, high + 1);
            return;
        }

        else if(currElement > target) high--;
        else low++;
    }
    printf("Element %d not found in the matrix.", target);
}

int main() {
    int rows, cols;
    printf("Enter no of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) scanf("%d", &matrix[i][j]);
    }

    int target;
    printf("Enter target: ");
    scanf("%d", &target);
    result(rows, cols, matrix, target);
}