#include <stdio.h>
#include <stdlib.h>  /* for  atof() */
#include <ctype.h>   /* for isdigit() */
#include <math.h>    /* for fmod() */
#define MAXOP   100  /* max size of operand or operator */
#define NUMBER  '0'  /* signal that a number was found */
#define MAXVAL 100   /* maximum depth of val stack */

int getop(char []);
void push(double);
double pop(void);
void print_top(void);
void duplicate_top(void);
void swap_top(void);
void clear_stack(void);

/* Global variables */
int sp = 0;           /* next free stack position */
double val[MAXVAL];   /* value stack */

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
            case '%':
                op2 = pop();
                push(fmod(pop(), op2));
                break;
            case 'p':  /* New case to print the top element */
                print_top();
                break;
            case 'd':  /* New case to duplicate the top element */
                duplicate_top();
                break;
            case 's':  /* New case to swap the top two elements */
                swap_top();
                break;
            case 'c':  /* New case to clear the stack */
                clear_stack();
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

/* print_top: print the top element of the stack without popping */
void print_top(void)
{
    if (sp > 0)
        printf("Top of stack: %.8g\n", val[sp - 1]);
    else
        printf("error: stack empty\n");
}

/* duplicate_top: duplicate the top element of the stack */
void duplicate_top(void)
{
    if (sp > 0) {
        double top = val[sp - 1];
        push(top);
    } else
        printf("error: stack empty\n");
}

/* swap_top: swap the top two elements of the stack */
void swap_top(void)
{
    if (sp > 1) {
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    } else
        printf("error: stack has fewer than two elements\n");
}

/* clear_stack: clear the stack */
void clear_stack(void)
{
    sp = 0;  /* Reset stack pointer */
}

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    
    while ((s[0] = c = getchar()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;  /* not a number */
    i = 0;
    if (c == '-') {
        if (isdigit(c = getchar()) || c == '.')
            s[++i] = c;  // Negative number
        else {
            if (c != EOF)
                ungetc(c, stdin);  // Push back non-digit character
            return '-';
        }
    }
    if (isdigit(c))  /* collect integer part */
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.')    /* collect fraction part */
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetc(c, stdin);
    return NUMBER;
}
