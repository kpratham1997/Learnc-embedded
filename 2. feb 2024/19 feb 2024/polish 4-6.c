//ex 4.6

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
    int i,type,var=0;
    double op2,v;
    char s[MAXOP];
    double variable[26];

    for(i=0;i<26;i++){
        variable[i]=0.0;

    }
    
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
            case '=':
                pop();
                if(var>='A'&& var <='Z'){
                    variable[var-'A']=pop();
                }else{

                    printf("no variable name\n");
                }
                break;
            case '\n':
                v=pop();
                printf("Result: %.8g\n", v);
                break;
            default:
                if(type>='A' && type <='Z'){
                    push(variable[type-'A']);
                }else if(type =='v'){
                    push(v);
                }else{
                    printf("error: unknown command %s\n", s);
                }
                break;
        }
        var=type;
    }
    return 0;
}

#define MAXVAL 100  /* maximum depth of val stack */
int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */

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
    if (c == '-') {  /* check for negative number */
        if (isdigit(c = getchar()) || c == '.') {
            s[++i] = c;
        } else {
            ungetc(c, stdin);  /* put back non-digit character */
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
