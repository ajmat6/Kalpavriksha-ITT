#include<stdio.h>

void result(int rows, int cols, int matrix[][cols]) {
    // using indexing:
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // using pointers:
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) printf("%d ", *(*(matrix + i) + j));
        printf("\n");
    }

    // as 1d array:
    int *ptr = &matrix[0][0];
    for(int i=0; i<rows*cols; i++) {
        printf("%d ", *(ptr + i));
    }
}

int main() {
    int rows, cols;
    printf("Enter no of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) scanf("%d", &matrix[i][j]);
    }

    result(rows, cols, matrix);
    return 0;
}