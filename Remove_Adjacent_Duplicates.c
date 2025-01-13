#include<stdio.h>
#include<string.h>

void result(char input[]) {
    int index = 0;
    int indexTrack = 0;
    int size = strlen(input);

    while(input[index] != '\0') {
        int count = 0;
        char currChar = input[index];
        while(input[index] != '\0' && input[index] == currChar) {
            count++;
            index++;
        }
        if(count == 1) input[indexTrack++] = currChar;
    }
    input[indexTrack] = '\0';
    if(indexTrack == size) return;
    result(input);
}

int main() {
    char input[7];
    printf("Enter string: ");
    scanf("%s", input);

    result(input);

    if(strlen(input) != 0) printf("%s", input);
    else printf("All characters removed!");
    
    return 0;
}