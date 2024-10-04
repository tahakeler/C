#include <stdio.h>
#include <math.h>
#include <string.h>

// Structure to store inventory information for each type of noodle
typedef struct {
    char name[20];
    int price;
    int available;
    int sold;
} NoodleType;

// Function to initialize inventory information
void initializeInventory(NoodleType *noodleTypes, int numTypes) {
    for (int i = 0; i < numTypes; i++) {
        printf("Enter the name, price, and initial quantity of %s noodles: ", noodleTypes[i].name);
        scanf("%s %d %d", noodleTypes[i].name, &noodleTypes[i].price, &noodleTypes[i].available);
        noodleTypes[i].sold = 0;
    }
}

// Function to calculate and print the cost of noodles for a customer
int calculateCost(NoodleType *noodleTypes, int numTypes, char *noodleName, int quantity) {
    int cost = 0;
    for (int i = 0; i < numTypes; i++) {
        if (strcmp(noodleTypes[i].name, noodleName) == 0) {
            if (noodleTypes[i].available >= quantity) {
                cost = quantity * noodleTypes[i].price;
                noodleTypes[i].available -= quantity;
                noodleTypes[i].sold += quantity;
            } else {
                printf("Not enough %s noodles in stock.\n", noodleName);
            }
            break;
        }
    }
    return cost;
}

int main() {
    int numTypes = 4;  // Number of noodle types
    NoodleType noodleTypes[numTypes];

    // Initialize inventory
    initializeInventory(noodleTypes, numTypes);

    int totalRevenue = 0;

    while (1) {
        char noodleName[20];
        int quantity;

        printf("Enter the noodle type and quantity (EOD to end the day): ");
        scanf("%s", noodleName);

        if (strcmp(noodleName, "EOD") == 0) {
            // End of day, print sales report and inventory report
            printf("Sales Report:\n");
            int mostSold = 0;
            int leastSold = noodleTypes[0].sold;
            int mostSoldIndex = 0;
            for (int i = 0; i < numTypes; i++) {
                printf("Sold %d bowls of %s noodles for %d baht each.\n", noodleTypes[i].sold, noodleTypes[i].name, noodleTypes[i].price);
                totalRevenue += (noodleTypes[i].sold * noodleTypes[i].price);
                if (noodleTypes[i].sold > mostSold) {
                    mostSold = noodleTypes[i].sold;
                    mostSoldIndex = i;
                }
                if (noodleTypes[i].sold < leastSold) {
                    leastSold = noodleTypes[i].sold;
                }
            }
            printf("Total revenue for the day: %d baht\n", totalRevenue);
            printf("Most popular noodle: %s\n", noodleTypes[mostSoldIndex].name);
            printf("Least popular noodle: ");
            for (int i = 0; i < numTypes; i++) {
                if (noodleTypes[i].sold == leastSold) {
                    printf("%s ", noodleTypes[i].name);
                }
            }
            printf("\n");

            printf("Inventory Report:\n");
            for (int i = 0; i < numTypes; i++) {
                printf("%s: Start - %d, Sold - %d, End - %d\n", noodleTypes[i].name, 
                       noodleTypes[i].available + noodleTypes[i].sold, noodleTypes[i].sold, noodleTypes[i].available);
            }
            break;  // End the program
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Calculate and print the cost for the customer
        int cost = calculateCost(noodleTypes, numTypes, noodleName, quantity);
        if (cost > 0) {
            printf("Cost for %d bowls of %s noodles: %d baht\n", quantity, noodleName, cost);
        }
    }

    return 0;
}
