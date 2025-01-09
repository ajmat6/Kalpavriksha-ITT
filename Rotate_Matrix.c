#include<stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void result(int rows, int cols, int matrix[][cols]) {
    // transpose matrix:
    for(int i=0; i<rows; i++) {
        for(int j=i+1; j<cols; j++) {
            if(i != j) swap(&matrix[i][j], &matrix[j][i]);
        }
    }

    // reverse rows:
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols/2; j++) swap(&matrix[i][j], &matrix[i][cols - j - 1]);
    }

    // print matrix:
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) printf("%d ", matrix[i][j]);
        printf("\n");
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
}