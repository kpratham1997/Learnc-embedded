#include <stdio.h>
#include <ctype.h>
   /* atof:  convert string s to double */

double atof(char s[]);

int atoi(char s[])
{
  

    return (int) atof(s);



}

double atof(char s[])
   {
       double val, power;
       int i, sign;
       for (i = 0; isspace(s[i]); i++)  /* skip white space */
           ;
       sign = (s[i] == '-') ? -1 : 1;
       if (s[i] == '+' || s[i] == '-')
           i++;
       for (val = 0.0; isdigit(s[i]); i++)
           val = 10.0 * val + (s[i] - '0');
       if (s[i] == '.')
           i++;
       for (power = 1.0; isdigit(s[i]); i++) {
           val = 10.0 * val + (s[i] - '0');
           power *= 10;
       }
       return sign * val / power;
}


int main(){
    char s[] ="123";
    int abc=atoi(s);
    double abcd=atof(s);
    

    printf("%d", abc);
    printf(" %lf",abcd);




}


