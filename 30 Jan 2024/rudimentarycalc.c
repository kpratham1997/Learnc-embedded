#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

int get_line(char line[], int maxline);
double atof(char s[]);

int main(){
    double sum,atof(char []);
    char line[MAXLINE];
    int get_line(char line[],int max);
    sum=0;
    while(get_line(line,MAXLINE)>0){
        printf("\t%g\n",sum +=atof(line));
        

    }




}
int get_line(char line[], int maxline) {
    int c, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

 
   /* atof:  convert string s to double */
double atof(char s[])
   {
       double val, power;
       int i, sign;
       for (i = 0; isspace(s[i]); i++)  /* skip white space */{

       
       }
       sign = (s[i] == '-') ? -1 : 1;
       if(s[i] == '+' || s[i] == '-'){
           i++;
       }
       for (val = 0.0; isdigit(s[i]); i++){
           val = 10.0 * val + (s[i] - '0');
       }
       if (s[i] == '.'){
           i++;
       }
       for (power = 1.0; isdigit(s[i]); i++) {
           val = 10.0 * val + (s[i] - '0');
           power *= 10;
       }
       return sign * val / power;
}