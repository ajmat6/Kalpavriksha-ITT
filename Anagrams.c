#include<stdio.h>
#include<string.h>

void result(char str1[], char str2[]) {
    int freq1[256] = {0};
    int freq2[256] = {0};

    for(int i=0; str1[i] != '\0'; i++) {
        freq1[str1[i]]++;
        freq2[str2[i]]++;
    }

    for(int i=0; i<256; i++) {
        if(freq1[i] != freq2[i]) {
            printf("False");
            return;
        }
    }

    printf("True");
}

int main() {
    char str1[1000];
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