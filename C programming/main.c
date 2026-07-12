#include <stdio.h>
#include <string.h>//output -- gcc main.c output -- a.exe 
struct Book {
    char name[100];
    char author[100];
    int year;
};
void displayLibrary(struct Book library[], int count) {
    if (count == 0) { 
        printf("\nThe library is empty.\n");
        return;
    }
    printf("\n%-5s | %-25s | %-25s | %-5s\n", "ID", "Book Name", "Author", "Year");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d | %-25s | %-25s | %-5d\n", i + 1, library[i].name, library[i].author, library[i].year);
    }
}
int main() {
    struct Book library[100]; // Array of 100 books
    int bookCount = 0;
    int choice;
    while (1) {
        printf("\n--- Library Menu ---");
        printf("\n1. Add Book");
        printf("\n2. View All Books");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        // This clears the 'Enter' key from the buffer so gets() doesn't skip
        getchar();
        if (choice == 1) {
            if (bookCount < 100) {
                printf("Enter Book Name: ");
                gets(library[bookCount].name);
                printf("Enter Author Name: ");
                gets(library[bookCount].author);
                printf("Enter Release Year: ");
                scanf("%d", &library[bookCount].year);
                bookCount++;
                printf("Book saved successfully!\n");
            } else {
                printf("Library is full!\n");
            }
        }
        else if (choice == 2) {
            displayLibrary(library, bookCount);
        }
        else if (choice == 3) {
            printf("Closing the library program. Goodbye!\n");
            break;
        }
        else {
            printf("Invalid option!\n");
        }
    }
    return 0;
}
