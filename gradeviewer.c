#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10

struct Student {
    int id;
    char firstName[32];
    int grade;
};

void bubbleSort(struct Student students[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].id > students[j + 1].id) {
                // Swap students
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;

    printf("Welcome to Grade Viewer!\n");

    while (numStudents < MAX_STUDENTS) {
        printf("Enter Id for student %d (5 digits, 0 to end): ", numStudents + 1);
        scanf("%d", &students[numStudents].id);

        if (students[numStudents].id == 0) {
            break;
        }

        printf("Enter first name for student %d: ", numStudents + 1);
        scanf("%s", students[numStudents].firstName);

        printf("Enter course grade for %s: ", students[numStudents].firstName);
        scanf("%d", &students[numStudents].grade);

        numStudents++;
    }

    // Sort the students using bubble sort
    bubbleSort(students, numStudents);

    printf("\nYou've entered %d students\n", numStudents);
    printf("Here are the students before sorting:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d %s %d\n", students[i].id, students[i].firstName, students[i].grade);
    }

    printf("\nHere are the students, sorted from best to worst:\n");
    for (int i = numStudents - 1; i >= 0; i--) {
        printf("%d %s %d\n", students[i].id, students[i].firstName, students[i].grade);
    }

    return 0;
}
