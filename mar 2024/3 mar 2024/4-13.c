//4-13

#include <stdio.h>
#include <string.h>

void reverse_helper(char s[], int start, int end) {
    if (start >= end) {// 0>=13
        return;  // Base case: when start >= end, we're done
    }
    
    // Swap characters at start and end indices
    char temp = s[start];//t=s[0]='H'
    s[start] = s[end];//'H'='!'
    s[end] = temp;//!= temp

    // Recur with updated indices
    reverse_helper(s, start + 1, end - 1);
}

void reverse(char s[]) {
    int length = strlen(s);
    if (length <= 1) {
        return;  // No need to reverse if the string is empty or has only one character
    }
    reverse_helper(s, 0, length - 1);
}

int main() {
    char str[] = "Hello, World!";
    printf("Original string: %s\n", str);
    reverse(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
