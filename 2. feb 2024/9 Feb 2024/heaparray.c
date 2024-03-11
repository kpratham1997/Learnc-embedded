#include <stdlib.h> // for malloc, free
#include <stdio.h>

// Structure definition for fraction
struct fraction {
    int numerator;
    int denominator;
};

// Function definition for HeapArray
void HeapArray() {
    struct fraction* fracts;
    int i;

    // Allocate memory for the array of fractions
    fracts = malloc(sizeof(struct fraction) * 100);

    // Check if memory allocation was successful
    if (fracts == NULL) {
        // Handle allocation failure
        // For example, print an error message and return or exit
        printf("Memory allocation failed. Exiting...\n");
        return;
    }

    // Use the array like an array -- in this case set them all to 22/7
    for (i = 0; i < 99; i++) {
        fracts[i].numerator = 22;
        fracts[i].denominator = 7;
    }

    for (i = 0; i < 99; i++) {
        printf("Fraction %d: %d/%d\n", i + 1, fracts[i].numerator, fracts[i].denominator);
    }

    // Deallocate the whole array to free the memory
    free(fracts);
}

int main() {
    // Call the HeapArray function
    HeapArray();

    // Return 0 to indicate successful completion of the program
    return 0;
}
