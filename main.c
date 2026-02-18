#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ENTRIES 100

int main() {
    char websites[MAX_ENTRIES][51];      
    char passwords[MAX_ENTRIES][31];      
    int count = 0;

    char input[100];
    while (true) {
        printf("\nEnter website and password (space separated)\n");
        printf("(type 'quit' to exit, 'pm' to view all):\n");
        fgets(input, sizeof(input), stdin);


        input[strcspn(input, "\n")] = '\0';


        if (strcmp(input, "quit") == 0) break;
        if (strcmp(input, "pm") == 0) {
            printf("\nSaved Passwords:\n");
            for (int i = 0; i < count; i++) {
                printf("%s : %s\n", websites[i], passwords[i]);
            }
            continue;
        }

        char *space = strchr(input, ' ');
        if (!space) {
            printf("Invalid input! Enter in format: website password\n");
            continue;
        }

        *space = '\0'; 
        char *website = input;
        char *password = space + 1;

        if (count < MAX_ENTRIES) {
            strncpy(websites[count], website, 50);
            websites[count][50] = '\0';
            strncpy(passwords[count], password, 30);
            passwords[count][30] = '\0';
            count++;
            printf("Saved!\n");
        } else {
            printf("Password manager full!\n");
        }
    }

    printf("Exiting Password Manager.\n");
    return 0;
}
