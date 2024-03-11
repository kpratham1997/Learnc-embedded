//4.7 ungets

#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */
int len;

/* push character back onto input */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
        printf("ungetch buf[bufp++]: %c\n ",buf[bufp++]);
}

/* push back entire string onto input */
void ungets(char s[]) {
    len = strlen(s);
    printf("ungets len : %d\n ",len);
    while (len > 0)
        ungetch(s[--len]);  
      
}

void print_buf(){
    printf("Buffer data");
    for (int i=0;i<len;i++){
        printf("%c",buf[i]);

    }



}

/* read a character from input buffer */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

int main() {
    char input[] = "Hello, World!";
    ungets(input);
    print_buf();
    
    /* Reading characters from input buffer using getch */
    int c;
    while ((c = getch()) != EOF) {
        putchar(c);
    }
    
    return 0;
}
