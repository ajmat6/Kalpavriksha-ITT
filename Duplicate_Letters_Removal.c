#include<stdio.h>

void result(char input[]) {
    int freq[256] = {0};
    char ans[1000];
    int ansIndex = 0;

    for(int i=0; input[i] != '\0'; i++) {
        if(freq[input[i]] == 0) {
            ans[ansIndex++] = input[i];
            freq[input[i]] = 1;
        }
    }

    ans[ansIndex] = '\0';
    printf("%s", ans);
}

int main() {
    char input[1000];
    printf("Enter string: ");
    scanf("%s", input);
    result(input);
    
    return 0;
}