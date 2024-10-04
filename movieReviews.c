#include <stdio.h>
#include <stdlib.h>

#define MAX_REVIEWS 20
#define MAX_NAME_LENGTH 64
#define MAX_TEXT_LENGTH 128

// Define a structure for a date
struct Date {
    int day;
    int month;
    int year;
};

// Define a structure for a movie review
struct MovieReview {
    char movieName[MAX_NAME_LENGTH];
    int rating;
    char reviewText[MAX_TEXT_LENGTH];
    struct Date reviewDate;
};

// Function to validate a date
int isValidDate(struct Date date) {
    // Basic date validation
    return (date.day >= 1 && date.day <= 31) &&
           (date.month >= 1 && date.month <= 12) &&
           (date.year >= 0);
}

// Function to display reviews with a specific rating
void displayReviewsByRating(struct MovieReview reviews[], int numReviews, int rating) {
    printf("Reviews rated %d\n", rating);

    for (int i = 0; i < numReviews; i++) {
        if (reviews[i].rating == rating) {
            printf("Movie name: %s\n", reviews[i].movieName);
            printf("Review date: %02d\\%02d\\%04d\n", reviews[i].reviewDate.day, reviews[i].reviewDate.month, reviews[i].reviewDate.year);
            printf("Rating: %d\n", reviews[i].rating);
            printf("Review text: %s\n", reviews[i].reviewText);
        }
    }
}

int main() {
    struct MovieReview reviews[MAX_REVIEWS];
    int numReviews = 0;

    while (numReviews < MAX_REVIEWS) {
        printf("Enter movie name (max %d chars, DONE to finish): ", MAX_NAME_LENGTH);
        char movieName[MAX_NAME_LENGTH];
        scanf("%s", movieName);

        if (strcmp(movieName, "DONE") == 0) {
            break;
        }

        if (strlen(movieName) > MAX_NAME_LENGTH) {
            printf("Movie name is too long. Try again.\n");
            continue;
        }

        printf("Enter your rating for this movie (1 to 5): ");
        int rating;
        scanf("%d", &rating);

        if (rating < 1 || rating > 5) {
            printf("Invalid rating. Please enter a rating from 1 to 5.\n");
            continue;
        }

        printf("Enter review text (max %d characters): ", MAX_TEXT_LENGTH);
        char reviewText[MAX_TEXT_LENGTH];
        scanf("%s", reviewText);

        if (strlen(reviewText) > MAX_TEXT_LENGTH) {
            printf("Review text is too long. Try again.\n");
            continue;
        }

        printf("Enter review date in the form DD/MM/YYYY: ");
        struct Date reviewDate;
        scanf("%d/%d/%d", &reviewDate.day, &reviewDate.month, &reviewDate.year);

        if (!isValidDate(reviewDate)) {
            printf("Invalid date format. Please enter a valid date.\n");
            continue;
        }

        // Store the review in the array
        strcpy(reviews[numReviews].movieName, movieName);
        reviews[numReviews].rating = rating;
        strcpy(reviews[numReviews].reviewText, reviewText);
        reviews[numReviews].reviewDate = reviewDate;
        numReviews++;
    }

    // Search for movies by rating
    while (1) {
        printf("Search for movies with what rating (1 to 5, 0 to exit)? ");
        int searchRating;
        scanf("%d", &searchRating);

        if (searchRating < 1 || searchRating > 5) {
            if (searchRating == 0) {
                break;
            }
            printf("Invalid rating. Please enter a rating from 1 to 5.\n");
            continue;
        }

        displayReviewsByRating(reviews, numReviews, searchRating);
    }

    return 0;
}
