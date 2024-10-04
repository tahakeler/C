#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 200
#define MAX_ID_LENGTH 9
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 11

struct Student {
    char id[MAX_ID_LENGTH];
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char dateOfBirth[MAX_DATE_LENGTH];
};

void addStudent(struct Student students[], int *numStudents) {
    if (*numStudents >= MAX_STUDENTS) {
        printf("Database is full. Cannot add more students.\n");
        return;
    }

    printf("Enter student ID (8 digits, unique): ");
    char newId[MAX_ID_LENGTH];
    scanf("%s", newId);

    for (int i = 0; i < *numStudents; i++) {
        if (strcmp(students[i].id, newId) == 0) {
            printf("Student with this ID already exists. Please choose a unique ID.\n");
            return;
        }
    }

    printf("Enter student's first name: ");
    char newFirstName[MAX_NAME_LENGTH];
    scanf("%s", newFirstName);

    printf("Enter student's last name: ");
    char newLastName[MAX_NAME_LENGTH];
    scanf("%s", newLastName);

    printf("Enter student's date of birth (dd/mm/yyyy): ");
    char newDateOfBirth[MAX_DATE_LENGTH];
    scanf("%s", newDateOfBirth);

    strcpy(students[*numStudents].id, newId);
    strcpy(students[*numStudents].firstName, newFirstName);
    strcpy(students[*numStudents].lastName, newLastName);
    strcpy(students[*numStudents].dateOfBirth, newDateOfBirth);
    (*numStudents)++;

    printf("Student added successfully.\n");
}

void lookupStudent(const struct Student students[], int numStudents) {
    printf("Enter student ID to look up: ");
    char searchId[MAX_ID_LENGTH];
    scanf("%s", searchId);

    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].id, searchId) == 0) {
            printf("Student found:\n");
            printf("ID: %s\n", students[i].id);
            printf("Name: %s %s\n", students[i].firstName, students[i].lastName);
            printf("Date of Birth: %s\n", students[i].dateOfBirth);
            return;
        }
    }

    printf("Student not found.\n");
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;
    char choice[10];

    while (1) {
        printf("Enter 'ADD' to add a new student, 'LOOKUP' to find a student, or 'DONE' to exit: ");
        scanf("%s", choice);

        if (strcmp(choice, "ADD") == 0) {
            addStudent(students, &numStudents);
        } else if (strcmp(choice, "LOOKUP") == 0) {
            lookupStudent(students, numStudents);
        } else if (strcmp(choice, "DONE") == 0) {
            break;
        } else {
            printf("Invalid choice. Please enter 'ADD', 'LOOKUP', or 'DONE'.\n");
        }
    }

    return 0;
}