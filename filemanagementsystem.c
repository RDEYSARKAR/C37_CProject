#include <stdio.h>
#include <stdlib.h>

void createFile();
void displayFile();
void appendToFile();
void deleteFile();

int main() {
    int choice;

    while (1) {
        printf("1. Create file\n");
        printf("2. Display file contents\n");
        printf("3. Append to file\n");
        printf("4. Delete file\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            createFile();
        } else if (choice == 2) {
            displayFile();
        } else if (choice == 3) {
            appendToFile();
        } else if (choice == 4) {
            deleteFile();
        } else if (choice == 5) {
            printf("Exiting program.\n");
            exit(0);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void createFile() {
    char filename[50];
    FILE *fp;

    printf("Enter the filename to create: ");
    scanf("%s", filename);
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file.\n");
        exit(1);
    }
    printf("File created successfully!\n");
    fclose(fp);
}

void displayFile() {
    char filename[50], ch;
    FILE *fp;

    printf("Enter the filename to display: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    printf("Contents of file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);
}

void appendToFile() {
    char filename[50], ch;
    FILE *fp;

    printf("Enter the filename to append: ");
    scanf("%s", filename);
    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    printf("Enter data to append to the file: ");
    while ((ch = getchar()) != '\n') {
        fputc(ch, fp);
    }
    fclose(fp);
}

void deleteFile() {
    char filename[50];

    printf("Enter the filename to delete: ");
    scanf("%s", filename);
    if (remove(filename) == 0) {
        printf("File deleted successfully!\n");
    } else {
        printf("Error deleting file.\n");
        exit(1);
    }
}