//4-11

#include <stdio.h>
#include <stdlib.h>  /* for  atof() */
#include <ctype.h>   /* for isdigit() */
#include <math.h>    /* for fmod() */
#define MAXOP   100  /* max size of operand or operator */
#define NUMBER  '0'  /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    
    printf("Enter RPN expression followed by Enter (Ctrl+D to exit):\n");
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':  /* Modulus operator */
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divisor\n");
                break;
            case 's':
                push(sin(pop()));
                break;
            case 'e':
                push(exp(pop()));
                break;
            case 'p':
                op2=pop();
                push(pow(pop(),op2));
                break;
            case '\n':
                printf("Result: %.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100  /* maximum depth of val stack */
int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */ //array name val which can hold 100 numbers.

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[])
{
    static int last_char = '\0'; // Internal static variable to store the last character read

    int i, c;

    // Use the last character read if available
    if (last_char != '\0') {
        c = last_char;
        last_char = '\0';
    } else {
        c = getchar();
    }

    while (c == ' ' || c == '\t') // Skip white characters and tabs
        c = getchar();

    s[0] = c;
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c;  // Not a number

    i = 0;
    if (c == '-') {  // Check for negative number
        if (isdigit(c = getchar()) || c == '.') {
            s[++i] = c;
        } else {
            last_char = c;  // Save the non-digit character for next call
            return '-';
        }
    }
    if (isdigit(c)) {  // Collect integer part
        while (isdigit(s[++i] = c = getchar()))
            ;
    }
    if (c == '.') {  // Collect fraction part
        while (isdigit(s[++i] = c = getchar()))
            ;
    }
    s[i] = '\0';
    return NUMBER;
}