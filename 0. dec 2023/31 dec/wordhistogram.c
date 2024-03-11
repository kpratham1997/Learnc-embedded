#include <stdio.h>

#define MAX_LENGTH 20 // Maximum word length to consider

int main() {
    int wordLengths[MAX_LENGTH + 1]; // Array to store word lengths count
   

    // Initialize the array to zeros
    for (int i = 0; i <= MAX_LENGTH; ++i) {
        wordLengths[i] = 0;
    }
    
    int c, currentLength;
    currentLength = 0;

    // Read input and count word lengths
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (currentLength > 0 && currentLength <= MAX_LENGTH) {
                ++wordLengths[currentLength];
            }
            currentLength = 0; // Reset word length for next word
        } else {
            ++currentLength; // Increment word length
        }
    }

    // Print the histogram
    printf("Length\tCount\tHistogram\n");
    for (int i = 1; i <= MAX_LENGTH; ++i) {
        printf("%d\t%d\t", i, wordLengths[i]);
        for (int j = 0; j < wordLengths[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
