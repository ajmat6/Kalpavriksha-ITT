#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isVowel(char* name) {
    char ch = name[0];
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return 1;
    return 0;
}

void result(int rows, int cols) {
    char matrix[rows][cols][51];
    int vowelStartNames = 0;
    int maxLengthNameSize = 0;
    char maxLengthName[51];

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("Name at (%d,%d): ", i, j);
            scanf("%s", matrix[i][j]);

            if(strlen(matrix[i][j]) < 1 || strlen(matrix[i][j]) > 50) {
                printf("Invalid input for name!");
                exit(0);
            }

            if(isVowel(matrix[i][j])) vowelStartNames++; 
            if(strlen(matrix[i][j]) > maxLengthNameSize) {
                maxLengthNameSize = strlen(matrix[i][j]);
                strcpy(maxLengthName, matrix[i][j]);
            }
        }
    }

    printf("2d array of names is:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) printf("%s ", matrix[i][j]);
        printf("\n");
    }

    printf("Number of names starting with a vowel: %d\n", vowelStartNames);
    printf("The longest name: %s", maxLengthName);
}

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if(rows < 1 || rows > 10 || cols < 1 || cols > 101) {
        printf("Invalid input of rows and cols!");
        return 0;
    }

    result(rows, cols);

    return 0;
}