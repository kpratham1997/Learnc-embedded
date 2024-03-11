#include <stdio.h>

//code not working
#define TAB_WIDTH 4

int main() {
    int c;
    int charCount = 1;
    int spacesToNextTabStop=0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            spacesToNextTabStop = TAB_WIDTH - (charCount-1) % TAB_WIDTH;
            for (int i = 0; i < spacesToNextTabStop; ++i) {
                putchar(' ');
                ++charCount;
            }
        } else if (c == '\n') {
            putchar(c);
            charCount = 1;
        } else {
            putchar(c);
            ++charCount;
        }
    }

    return 0;
}
