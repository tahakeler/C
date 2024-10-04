#include <stdio.h>
#include <math.h>

void printTextureUnitPattern(int pattern[], int numTextureUnits) {
    for (int i = 0; i < numTextureUnits; i++) {
        printf("%d ", pattern[i]);
    }
    printf("\n");
}

void generateTextureUnitPatterns(int numTextureUnits) {
    int totalPatterns = (int)pow(2, numTextureUnits);

    for (int patternIndex = 0; patternIndex < totalPatterns; patternIndex++) {
        int pattern[numTextureUnits];

        for (int i = 0; i < numTextureUnits; i++) {
            pattern[i] = (patternIndex >> i) & 1;
        }

        printTextureUnitPattern(pattern, numTextureUnits);
    }
}

int main() {
    int numTextureUnits;

    printf("Enter the number of texture units: ");
    scanf("%d", &numTextureUnits);

    if (numTextureUnits <= 0) {
        printf("Number of texture units should be greater than 0.\n");
        return 1;
    }

    printf("All possible texture unit patterns for %d units:\n", numTextureUnits);
    generateTextureUnitPatterns(numTextureUnits);

    return 0;
}
