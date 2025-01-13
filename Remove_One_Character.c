#include<stdio.h>
#include<string.h>

void result(char input[], char charToRemove) {
    int ansIndex = 0;
    int currIndex = 0;

    while(input[currIndex] != '\0') {
        if(input[currIndex] != charToRemove) {
            input[ansIndex++] = input[currIndex];
        }
        currIndex++;
    }
    input[ansIndex] = '\0';
    printf("%s", input);
}

int main() {
    char input[1000];
    printf("Enter string: ");
    fgets(input, sizeof(input), stdin);
    if(input[strlen(input) - 1] == '\n') input[strlen(input) - 1] = '\0';

    int charToRemove;
    printf("Enter the character to remove: ");
    scanf("%c", &charToRemove);
    result(input, charToRemove);
    
    return 0;
}