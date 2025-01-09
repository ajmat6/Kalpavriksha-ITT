#include<stdio.h>

void result(int rows, int cols, int matrix[][cols]) {
    int sum = 0;
    int col = cols - 1;
    for(int row=0; row<rows; row++) {
        sum += matrix[row][row];
        if(row != col) sum += matrix[row][col];
        col--;
    }
    printf("%d", sum);
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