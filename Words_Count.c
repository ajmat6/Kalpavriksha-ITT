#include<stdio.h>
#include<string.h>

void result(char input[]) {
    int index = 0;
    int wordsCount = 0;
    while(input[index] != '\0') {
        if(input[index] == ' ') index++;
        else {
            while(input[index] != '\0' && input[index] != ' ') index++;
            wordsCount++;
        }
    }
    printf("%d", wordsCount);
}

int main() {
    char input[1000];
    printf("Enter string: ");
    fgets(input, sizeof(input), stdin);
    if(input[strlen(input) - 1] == '\n') input[strlen(input) - 1] = '\0';
    result(input);

    return 0;
}