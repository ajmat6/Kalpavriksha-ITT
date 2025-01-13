#include<stdio.h>
#include<string.h>

void result(char input[]) {
    char ans[1000];
    int ansIndex = 0;

    int index = 0;
    while(input[index] != '\0') {
        int currCharCount = 0;
        char currChar = input[index];
        while(input[index] != '\0' && input[index] == currChar) {
            index++;
            currCharCount++;
        }
        ans[ansIndex] = currChar;
        ans[ansIndex + 1] = '0' + currCharCount;
        ansIndex += 2;
    }

    ans[ansIndex] = '\0';
    if(strlen(ans) <= strlen(input)) printf("%s", ans);
    else printf("%s", input);
}

int main() {
    char input[1000];
    printf("Enter string: ");
    fgets(input, sizeof(input), stdin);
    if(input[strlen(input) - 1] == '\n') input[strlen(input) - 1] = '\0';
    
    result(input);
    
    return 0;
}