#include<stdio.h>
#include<string.h>

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void findPermutations(char input[], int inputLen, char allPermutations[][inputLen + 1], int* permuteIndex, int currIndex) {
    if(currIndex == inputLen) {
        strcpy(allPermutations[*permuteIndex], input);
        *permuteIndex += 1;
        return;
    }

    for(int i=currIndex; i<inputLen; i++) {
        swap(&input[currIndex], &input[i]);
        findPermutations(input, inputLen, allPermutations, permuteIndex, currIndex + 1);
        swap(&input[currIndex], &input[i]);
    }
}

void result(char input[]) {
    int size = strlen(input);
    int totalPermutations = 1;
    for(int i=size; i>=1; i--) totalPermutations *= i;

    char allPermutations[totalPermutations][size + 1];
    int permuteIndex = 0;
    findPermutations(input, size, allPermutations, &permuteIndex, 0);

    printf("All Permutations are: ");
    for(int i=0; i<totalPermutations; i++) {
        printf("%s ", allPermutations[i]);
    }
}

int main() {
    char input[7];
    printf("Enter string: ");
    scanf("%s", input);
    result(input);
    return 0;
}