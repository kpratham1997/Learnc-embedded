//4.8 ungets
#include <stdio.h>

char buf = 0;  /* variable to store the last character */

/* push character back onto input */
void ungetch(int c) {
    if (buf!= 0)
        printf("ungetch: too many characters\n");
    else //if buf=0
        buf = c; //buf=a
}

/* read a character from input buffer */
int getch(void) {
    int c;
    if (buf!= 0) {
        c = buf;//c=a
    } else {
        c = getchar();//c = "empty"
        buf=0;
    }
    return c;
}

int main() {
     int c;

    /* Test ungetch and getch */
    ungetch('a');
    
    /* Retrieve characters from buffer */
    c = getch();
    putchar(c);  /* Should output 'a' */
    
    return 0;
}
