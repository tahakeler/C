#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct competency {
    char semester[10];
    char code[10];
    char title[50];
    int credits;
} Competency;

int compare(const void *a, const void *b) {
    Competency *c1 = (Competency *) a;
    Competency *c2 = (Competency *) b;

    int res = strcmp(c1->semester, c2->semester);
    if (res == 0) {
        res = strcmp(c1->code, c2->code);
    }
    return res;
}

void print_competency(const void *a) {
    const Competency *c = (Competency *) a;
    printf("%s %s %s %d\n", c->semester, c->code, c->title, c->credits);
}

void search_competency(Competency *competencies, int n) {
    char semester[10];
    char code[10];

    printf("What code (<return> to exit)? ");
    scanf("%s", code);

    while (strcmp(code, "") != 0) {
        printf("What semester? ");
        scanf("%s", semester);

        Competency key = {semester, code, "", 0};
        Competency *found = (Competency *) bsearch(&key, competencies, n, sizeof(Competency), compare);

        if (found != NULL) {
            printf("Found: %s - %s - %d credits - %s\n", found->code, found->title, found->credits, found->semester);
        } else {
            printf("Competency not found\n");
        }

        printf("What code (<return> to exit)? ");
        scanf("%s", code);
    }

    printf("Goodbye!\n");
}

int main() {
    FILE *fp = fopen("competencies.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    Competency comp;
    Competency *competencies = NULL;
    int n = 0;

    while (fscanf(fp, "|%[^|]|%[^|]|%d|%s\n", comp.title, comp.code, &comp.credits, comp.semester) != EOF) {
        competencies = realloc(competencies, sizeof(Competency) * (n + 1));
        competencies[n] = comp;
        n++;
    }

    qsort(competencies, n, sizeof(Competency), compare);

    printf("Competencies in sorted order:\n");
    for_each(competencies, n, print_competency);

    search_competency(competencies, n);

    free(competencies);
    fclose(fp);

    return 0;
}