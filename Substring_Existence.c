#include<stdio.h>
#include<string.h>

void result(char text[], char pattern[]) {
    int textLen = strlen(text);
    int pattLen = strlen(pattern);

    for(int i=0; i<=(textLen - pattLen); i++) {
        int j=0;
        for(; j<pattLen; j++) {
            if(text[i + j] != pattern[j]) break;
        }
        if(j == pattLen) {
            printf("%d", i);
            return;
        }
    }
    printf("-1");
}

int main() {
    char text[1000];
    printf("Enter string: ");
    fgets(text, sizeof(text), stdin);
    if(text[strlen(text) - 1] == '\n') text[strlen(text) - 1] = '\0';

    char substring[1000];
    printf("Enter substring: ");
    fgets(substring, sizeof(substring), stdin);
    if(substring[strlen(substring) - 1] == '\n') substring[strlen(substring) - 1] = '\0';
    result(text, substring);

    return 0;
}