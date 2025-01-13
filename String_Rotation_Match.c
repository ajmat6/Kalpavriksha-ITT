#include<stdio.h>
#include<string.h>

void result(char str1[], char str2[]) {
    char concatString[2001];
    strcpy(concatString, str1);
    strcat(concatString, str1);
    
    int textLen = strlen(concatString);
    int pattLen = strlen(str2);

    for(int i=0; i<=(textLen - pattLen); i++) {
        int j=0;
        for(; j<pattLen; j++) {
            if(concatString[i + j] != str2[j]) break;
        }
        if(j == pattLen) {
            printf("True", i);
            return;
        }
    }
    printf("False");
}

int main() {
    char str1[2000];
    printf("Enter string 1: ");
    fgets(str1, sizeof(str1), stdin);
    if(str1[strlen(str1) - 1] == '\n') str1[strlen(str1) - 1] = '\0';

    char str2[1000];
    printf("Enter string 2: ");
    fgets(str2, sizeof(str2), stdin);
    if(str2[strlen(str2) - 1] == '\n') str2[strlen(str2) - 1] = '\0';

    if(strlen(str1) != strlen(str2)) printf("False");
    else result(str1, str2);

    return 0;
}