#include<stdio.h>
#include<string.h>
#include<limits.h>

void result(char str[], char pat[]) {
    int freq[255] = {0};
    for(int i=0; pat[i] != '\0'; i++) freq[pat[i]]++;
    int low = 0, high = 0, startIndex = 0, minLength = INT_MAX;
    int tCount = strlen(pat);

    
    while(str[high] != '\0') {
        if(freq[str[high]] > 0) tCount--;
        freq[str[high]]--;
        high++;

        while(tCount == 0) {
            if(high - low < minLength) {
                startIndex = low;
                minLength = high - low;
            }

            if(freq[str[low]] == 0) tCount++;
            freq[str[low]]++;
            low++;
        }
    }

    if(minLength == INT_MAX) printf("pat not found in str");
    else {
        printf("\"");
        for(int i=startIndex; i<(startIndex + minLength); i++) printf("%c", str[i]);
        printf("\"");
    }
}

int main() {
    char str[1000];
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);
    if(str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';

    char pat[1000];
    printf("Enter pat: ");
    fgets(pat, sizeof(pat), stdin);
    if(pat[strlen(pat) - 1] == '\n') pat[strlen(pat) - 1] = '\0';
    result(str, pat);

    return 0;
}