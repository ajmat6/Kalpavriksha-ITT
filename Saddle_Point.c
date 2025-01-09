#include<stdio.h>

void result(int rows, int cols, int matrix[][cols]) {
    int saddlePoint = -1;
    for(int i=0; i<rows; i++) {
        int minElement = matrix[i][0];
        int minCol = 0;
        for(int j=0; j<cols; j++) {
            if(matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                minCol = j;
            }
        }

        int maxElement = matrix[0][minCol];
        for(int j=0; j<rows; j++) {
            if(matrix[j][minCol] > maxElement) maxElement = matrix[j][minCol];
        }

        if(maxElement == minElement) {
            printf("%d", maxElement);
            return;
        }
    }
    printf("-1");
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