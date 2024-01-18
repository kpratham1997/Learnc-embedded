//Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2.
#include <stdio.h>

void squeezeAlternate(char s1[], char s2[]) {
    int i, j, k;
    int shouldDelete;

    for (i = j = 0; s1[i] != '\0'; i++) {
        shouldDelete = 0;

        // Check if s1[i] exists in s2
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                shouldDelete = 1;
                break;
            }
        }

        // If s1[i] does not exist in s2, keep it
        if (!shouldDelete) {
            s1[j++] = s1[i];
        }
    }

    s1[j] = '\0'; // Null-terminate the modified string
}

int main() {
    char str1[] = "Hello, World!";
    char str2[] = "aeiou";

    printf("Original String: %s\n", str1);
    squeezeAlternate(str1, str2);
    printf("Modified String: %s\n", str1);

    return 0;
}
