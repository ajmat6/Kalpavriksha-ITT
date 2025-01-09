#include<stdio.h>
#include<stdlib.h>

void result(int rows, int cols, int matrix[][cols]) {
    int* freqArray = (int*)calloc(101, sizeof(int));
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) freqArray[*(*(matrix + i) + j)]++;
    }

    printf("Frequency of Each Number\n");
    for(int i=1; i<101; i++) {
        if(*(freqArray + i) != 0) printf("%d -> %d times\n", i, *(freqArray + i));
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