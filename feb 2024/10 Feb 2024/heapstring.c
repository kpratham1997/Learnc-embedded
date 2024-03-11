#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* StringCopy(const char* string) {
    char* newString;
    int len;
    len = strlen(string) + 1;
    newString = (char*)malloc(sizeof(char) * len);  // allocate memory for the new string
    assert(newString != NULL); // simplistic error check (a good habit)
    strcpy(newString, string); // copy the passed in string to the new block
    return newString;   // return a pointer to the new block
}

int main() {
    const char* originalString = "Hello, World!";
    char* copiedString = StringCopy(originalString);
    
    printf("Original string: %s\n", originalString);
    printf("Copied string: %s\n", copiedString);
    
    // Don't forget to free the dynamically allocated memory
    free(copiedString);
    
    return 0;
}
