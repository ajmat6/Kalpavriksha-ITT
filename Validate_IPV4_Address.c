#include<stdio.h>

int isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

void result(char input[15]) {
    int currIndex = 0;
    int count = 0;
    while(input[currIndex] != '\0') {
        if(!isDigit(input[currIndex]) && input[currIndex] != '.') {
            printf("Invalid\n");
            return;
        }

        else if(isDigit(input[currIndex])) {
            if(input[currIndex] == '0' && input[currIndex + 1] != '\0' && isDigit(input[currIndex + 1]) && input[currIndex + 1] != '0') {
                printf("Invalid\n");
                return;
            }

            int value = 0;
            while(input[currIndex] != '\0' && isDigit(input[currIndex])) {
                value = value * 10 + input[currIndex] - '0';
                currIndex++;
            }

            if(value > 255) {
                printf("Invalid\n");
                return;
            }
            else count++;
        }

        else {
            if(input[currIndex] == '.' && (input[currIndex + 1] == '.' || input[currIndex] == '\0')) {
                printf("Invalid\n");
                return;
            }
            else currIndex++;
        }
    }
    if(count < 4) printf("invalid");
    else printf("Valid");
}

int main() {
    char input[15];
    scanf("%s", input);

    result(input);
    return 0;
}