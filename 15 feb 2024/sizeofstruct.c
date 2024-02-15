#include <stdio.h>

// Define the structure counter with bit-fields
struct counter {
    unsigned int little: 2;
    unsigned int medium: 4;
    unsigned int large: 6;
};

int main() {
    // Initialize a struct instance count with all zero values
    struct counter count = {0};

    // Loop to increment members 50 times
    for (int i = 0; i < 50; i++) {
        // Increment each member
        count.little++;
        count.medium++;
        count.large++;
    }

    // Print size of the count structure and unsigned int
    printf("Size of count structure: %zu bytes\n", sizeof(count));
    printf("Size of unsigned int: %zu bytes\n", sizeof(unsigned int));

    return 0;
}
