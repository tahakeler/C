#include <stdio.h>

int main() {
    int number_entered;
    int value_entered;
    int count = 0;

    printf("Check multiples of what number(Greater than 0 and less than 10): ");
    scanf("%d", &number_entered);

    while (number_entered != -1) {
        
        if (value_entered == 0) {
            printf("Error: Division by zero is not allowed.\n");
        } else if (number_entered % value_entered == 0) {
            printf("%d is a multiple of %d.\n", number_entered, value_entered);
            count++;
        } else {
            printf("%d is NOT evenly divisable by %d.\n", number_entered, value_entered);
        }

        printf("Check multiples of what number(Greater than 0 and less than 10): ");
        scanf("%d", &number_entered);
    }

    printf("Found %d multiples.\n", count);
    
    printf("You entered ", count ," values that were multiple of %d. \n Goodbye!", number_entered);
    scanf("%d", &value_entered);   

    return 0;
}

