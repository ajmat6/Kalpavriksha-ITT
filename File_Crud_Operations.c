#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "users.txt"

int checkFile(char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) return 0;
    fclose(file);
    return 1; 
}

void fileRemoval(int found, char* filename, char* tempFileName) {
    if (found) {
        remove(filename); 
        rename(tempFileName, filename); 
        printf("Operation successful.\n");
    } 
    else {
        remove(tempFileName); 
        printf("User with given id not found.\n");
    }
}

struct User {
    int id;
    char name[100];
    int age;
};

void addUser() {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        printf("Error occrured in opening file\n");
        return;
    }

    struct User newUser;
    printf("Enter User ID: ");
    scanf("%d", &newUser.id);

    getchar();  

    printf("Enter Name: ");
    fgets(newUser.name, 100, stdin);
    newUser.name[strcspn(newUser.name, "\n")] = '\0'; 

    printf("Enter Age: ");
    scanf("%d", &newUser.age);

    fprintf(file, "%d %s %d\n", newUser.id, newUser.name, newUser.age);
    fclose(file);
    printf("User add success\n");
}

void readUsers() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("Error occrured in opening file\n");
        return;
    }

    char buffer[10000];
    printf("All users are:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) { 
        printf("%s", buffer); 
    }

    fclose(file);
}

void updateUser() {
    int idToUpdate;
    printf("Enter User ID to update: ");
    scanf("%d", &idToUpdate);

    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("Error occrured in opening file\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        printf("Error occured in creating temporary file.\n");
        fclose(file);
        return;
    }

    int found = 0;
    struct User user;
    char buffer[10000]; 

    while (fgets(buffer, sizeof(buffer), file) != NULL) { 
        sscanf(buffer, "%d %s %d", &user.id, &user.name, &user.age); 
        if (user.id == idToUpdate) { 
            found = 1;
            printf("Enter new Name: ");
            getchar(); 
            fgets(user.name, 100, stdin);
            user.name[strcspn(user.name, "\n")] = '\0';  

            printf("Enter new Age: ");
            scanf("%d", &user.age);
            getchar();

            fprintf(tempFile, "%d %s %d\n", user.id, user.name, user.age); 
        } 
        else fputs(buffer, tempFile); 
    } 

    fclose(file); 
    fclose(tempFile); 
    fileRemoval(found, FILE_NAME, "temp.txt");
}

void deleteUser() {
    int idToDelete;
    printf("Enter User ID to delete: ");
    scanf("%d", &idToDelete);

    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    int found = 0;
    struct User user;
    char buffer[10000]; 

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "%d %99s %d", &user.id, &user.name, &user.age); 
        if (user.id == idToDelete) found = 1;
        else fputs(buffer, tempFile); 
    }

    fclose(file);
    fclose(tempFile);
    fileRemoval(found, FILE_NAME, "temp.txt");
}

void options() {
    while(1) {
        printf("\nAvailable Operations:\n");
        printf("Press 1 to Add User\n");
        printf("Press 2 to Read Users\n");
        printf("Press 3 to Update User\n");
        printf("Press 4 to Delete User\n");
        printf("Press 5 to Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) addUser();
        else if(choice == 2) readUsers();
        else if(choice == 3) updateUser();
        else if(choice == 4) deleteUser();
        else if(choice == 5) {
            printf("Exiting..\n");
            break;
        }
        else printf("Invalid choice. Try again.\n");
    }
}

int main() {
    if (!checkFile(FILE_NAME)) {
        FILE *file = fopen(FILE_NAME, "w");
        if (!file) {
            printf("Error occured in creating file\n");
            return 1;
        }
        fclose(file);
    }

    options();
    return 0;
}