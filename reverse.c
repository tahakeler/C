#include <stdio.h>
#include <string.h>

int main() {
    char input[100];

    printf("Welcome to Cat Search!\n");

    while (1) {
        printf("Type a string (<CR> to exit): ");
        fgets(input, sizeof(input), stdin);

        // Remove the newline character from the input
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Check if the user pressed Enter (empty string) to quit
        if (input[0] == '\0') {
            break;
        }

        // Check if the input contains "cat"
        if (strstr(input, "cat") != NULL) {
            printf("Found a cat!\n");
        } else {
            // Reverse the string
            int i, j;
            char temp;
            for (i = 0, j = strlen(input) - 1; i < j; i++, j--) {
                temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
            printf("Reverse is: %s\n", input);
        }
    }

    printf("Bye!\n");
    return 0;
}
