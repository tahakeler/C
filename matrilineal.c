#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 5

typedef struct Woman {
    char name[50];
    int timestamp;
    struct Woman *parent;
    struct Woman *children[MAX_CHILDREN];
    struct Woman *nextSameName;
    int numChildren;
} Woman;

Woman *findWoman(Woman *root, const char *name) {
    Woman *current = root;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0)
            return current;
        current = current->nextSameName;
    }

    return NULL;
}

Woman *addWoman(Woman *root, const char *name, Woman *mother) {
    Woman *newWoman = malloc(sizeof(Woman));
    strcpy(newWoman->name, name);
    newWoman->timestamp = (mother != NULL) ? (mother->timestamp + 1) : 0;
    newWoman->parent = mother;
    newWoman->numChildren = 0;
    newWoman->nextSameName = NULL;

    if (mother != NULL) {
        for (int i = 0; i < MAX_CHILDREN; i++) {
            if (mother->children[i] == NULL) {
                mother->children[i] = newWoman;
                mother->numChildren++;
                break;
            }
        }
    }

    Woman *existingWoman = findWoman(root, name);
    if (existingWoman != NULL) {
        if (existingWoman->parent == mother) {
            printf("Error: A woman with the same name already exists.\n");
            free(newWoman);
            return NULL;
        }
        while (existingWoman->nextSameName != NULL)
            existingWoman = existingWoman->nextSameName;
        existingWoman->nextSameName = newWoman;
    }

    return newWoman;
}

void printMother(Woman *woman) {
    if (woman->parent != NULL)
        printf("Mother: %s\n", woman->parent->name);
    else
        printf("Mother: N/A\n");
}

void printDaughters(Woman *woman) {
    printf("Daughters:\n");
    for (int i = 0; i < MAX_CHILDREN; i++) {
        Woman *daughter = woman->children[i];
        while (daughter != NULL) {
            printf("%s\n", daughter->name);
            daughter = daughter->nextSameName;
        }
    }
}

void printSisters(Woman *woman) {
    Woman *mother = woman->parent;
    if (mother == NULL) {
        printf("No sisters.\n");
        return;
    }

    printf("Sisters:\n");
    Woman *current = mother->children[0];
    while (current != NULL) {
        Woman *sister = current;
        while (sister != NULL) {
            if (sister != woman && sister->parent == mother)
                printf("%s\n", sister->name);
            sister = sister->nextSameName;
        }
        current = current->nextSameName;
    }
}

int main() {
    Woman *root = malloc(sizeof(Woman));
    strcpy(root->name, "Grandmother");
    root->timestamp = 0;
    root->parent = NULL;
    root->numChildren = 0;
    root->nextSameName = NULL;

    int option;
    char name[50];

    while (1) {
        printf("\n1. Add a woman\n2. Print the name of a woman's mother\n3. Print the names of all of a woman's daughters\n4. Print the names of all of a woman's sisters\n5. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the name of the woman: ");
                scanf("%s", name);
                Woman *mother = NULL;
                printf("Enter the mother's name (or 'N/A' if she has no mother): ");
                scanf("%s", name);
                if (strcmp(name, "N/A") != 0) {
                    mother = findWoman(root, name);
                    if (mother == NULL) {
                        printf("Error: Mother not found.\n");
                        continue;
                    }
                }
                Woman *woman = addWoman(root, name, mother);
                if (woman == NULL)
                    printf("Error: Woman already exists.\n");
                else
                    printf("Woman added successfully.\n");
                break;
            case 2:
                printf("Enter the name of the woman: ");
                scanf("%s", name);
                Woman *womanToFind = findWoman(root, name);
                if (womanToFind == NULL) {
                    printf("Error: Woman not found.\n");
                    continue;
                }
                printMother(womanToFind);
                break;
            case 3:
                printf("Enter the name of the woman: ");
                scanf("%s", name);
                Woman *womanToPrintDaughters = findWoman(root, name);
                if (womanToPrintDaughters == NULL) {
                    printf("Error: Woman not found.\n");
                    continue;
                }
                printDaughters(womanToPrintDaughters);
                break;
            case 4:
                printf("Enter the name of the woman: ");
                scanf("%s", name);
                Woman *womanToPrintSisters = findWoman(root, name);
                if (womanToPrintSisters == NULL) {
                    printf("Error: Woman not found.\n");
                    continue;
                }
                printSisters(womanToPrintSisters);
                break;
            case 5:
                printf("Exiting the program...\n");
                free(root);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    free(root);
    return 0;
}