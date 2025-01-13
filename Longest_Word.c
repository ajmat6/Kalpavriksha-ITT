#include<stdio.h>
#include<string.h>

void result(char input[]) {
    int index = 0;
    char maxLenWord[1000];
    int maxWordSize = 0;
    while(input[index] != '\0') {
        if(input[index] == ' ') index++;
        else {
            char currWord[1000];
            int currWorLen = 0;
            int currWordIndex = 0;
            while(input[index] != '\0' && input[index] != ' ') {
                currWord[currWordIndex++] = input[index];
                index++;
                currWorLen++;
            }

            currWord[currWordIndex] = '\0';
            if(currWorLen >= maxWordSize) {
                strcpy(maxLenWord, currWord);
                maxWordSize = currWorLen;
            }
        }
    }
    if(maxWordSize != 0) printf("%s", maxLenWord);
    else printf("No words!");
}

int main() {
    char input[1000];
    printf("Enter string: ");
    fgets(input, sizeof(input), stdin);
    if(input[strlen(input) - 1] == '\n') input[strlen(input) - 1] = '\0';
    result(input);

    return 0;
}