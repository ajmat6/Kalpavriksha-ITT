#include<stdio.h>
#include<string.h>
int currAnsSize = 0;
char ans[1000];

void checkAroundCenter(char input[], int low, int high) {
    while(low >= 0 && high < strlen(input) && input[low] == input[high]) {
        low--;
        high++;
    }

    if((high - low - 1) > currAnsSize) {
        int index = 0;
        for(int i=low+1; i<high; i++) ans[index++] = input[i];
        ans[index] = '\0';
        currAnsSize = high - low - 1;
    }
}

void result(char input[]) {
    // expand around a point:
    for(int i=0; input[i] != '\0'; i++) {
        checkAroundCenter(input, i - 1, i + 1);

        // two adjacent characters are same at center:
        if(i > 0 && input[i - 1] == input[i]) checkAroundCenter(input, i - 2, i + 1);
    }

    printf("Longest Palindromic string is: %s", ans);
}

int main() {
    char input[1000];
    printf("Enter string: ");
    scanf("%s", input);
    result(input);
    return 0;
}