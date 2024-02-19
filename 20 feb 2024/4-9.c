//4.9
#include <stdio.h>

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp=0;


/* push character back onto input */
void ungetch(int c) {
    if (bufp >= BUFSIZE){
        printf("too many characters\n");
    }else{
        buf[bufp++];
    }
   
}

/* read a character from input buffer */
int getch(void) {
    return(bufp>0)? buf[--bufp]:getchar();
}

int main() {
    char input[] = "Hello, World!";
    ungetch(EOF);  /* Example of pushing back EOF */
    
    /* Reading characters from input buffer using getch */
    int c;
    while ((c = getch()) != EOF) {
        putchar(c);
    }
    
    return 0;
}
