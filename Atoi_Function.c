#include<stdio.h>
#include<string.h>
#include<limits.h>

int isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

void result(char input[]) {
    long long value = 0;
    int sign = 1;
    int index = 0;

    if(input[index] == '-' || input[index] == '+') {
        if(input[index] == '-') sign = -1;
        index++;
    }

    while(input[index] != '\0' && input[index] == ' ') index++; // leading space

    while(input[index] != '\0' && isDigit(input[index])) {
        value = value * 10 + (input[index++] - '0');

        // out of bound
        if (sign == 1 && value > LLONG_MAX) break; 
        if (sign == -1 && -value < LLONG_MIN) break;
    }

    while(input[index] != '\0' && input[index] == ' ') index++; // trailing space

    if(index == strlen(input)) printf("%lld", value * sign);
    else printf("0");
}

int main() {
    char input[21];
    printf("Enter string: ");
    fgets(input, sizeof(input), stdin);
    if(input[strlen(input) - 1] == '\n') input[strlen(input) - 1] = '\0';

    result(input);

    return 0;
}