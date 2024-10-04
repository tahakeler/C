#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MovieStar {
    char first[20];
    char last[20];
    int num_movies;
    char gender;
    int popularity;
};

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Unable to open input file %s\n", argv[1]);
        return 1;
    }

    int num_stars;
    if (fscanf(input_file, "%d", &num_stars) != 1) {
        printf("Error: Unable to read number of stars from input file\n");
        fclose(input_file);
        return 1;
    }

    struct MovieStar *stars = calloc(num_stars, sizeof(struct MovieStar));
    if (stars == NULL) {
        printf("Error: Unable to allocate memory for %d stars\n", num_stars);
        fclose(input_file);
        return 1;
    }

    for (int i = 0; i < num_stars; ++i) {
        char line[100];
        if (fgets(line, sizeof(line), input_file) == NULL) {
            printf("Error: Unexpected end of input file\n");
            free(stars);
            fclose(input_file);
            return 1;
        }

        if (sscanf(line, "%s %s %d %c %d",
                   stars[i].first, stars[i].last,
                   &stars[i].num_movies,
                   &stars[i].gender,
                   &stars[i].popularity) != 5) {
            printf("Error: Unable to parse line %d in input file\n", i + 1);
            free(stars);
            fclose(input_file);
            return 1;
        }
    }

    fclose(input_file);

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Unable to open output file %s\n", argv[2]);
        free(stars);
        return 1;
    }

    for (int i = 0; i < num_stars; ++i) {
        fprintf(output_file, "Movie star #%d\n", i + 1);
        fprintf(output_file, "Name: %s %s\n", stars[i].first, stars[i].last);
        fprintf(output_file, "Gender: %c\n", stars[i].gender);
        fprintf(output_file, "Number of movies: %d\n", stars[i].num_movies);
        fprintf(output_file, "Popularity rating: %d\n\n", stars[i].popularity);
    }

    fclose(output_file);

    free(stars);
    return 0;
}