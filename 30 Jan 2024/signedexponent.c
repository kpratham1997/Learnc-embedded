#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]){
    double val, power, exp_val;
    int i, sign,exp_sign;
     for (i = 0; isspace(s[i]); i++){


     }
    sign=(s[i]=='-')?-1 :+1;

    if(s[i]=='+' || s[i]=='-' ){
        i++;
    }
    for(val=0.0;isdigit(s[i]);i++){

        val=10.0*val+(s[i]-'0');
    }
    if(s[i]=='.'){
        i++;

    }
    for(power=1.0;isdigit(s[i]);i++){

        val=10.0 * val+(s[i]-'0');
        power *=10;


    }

    val=sign*val/power;

    if(s[i]=='e'|| s[i]=='E'){
        i++;
        exp_sign=(s[i]=='-')?-1:1;

        if(s[i]=='+'|| s[i]=='-'){
            i++;
        }
        for(exp_val=0.0;isdigit(s[i]);i++){
            exp_val=10.0*exp_val+(s[i]-'0');

        }
        val *=pow(10,exp_sign*exp_val);
    }

return val;

}



int main(){
    char s[]="987.654e3";
    double result=atof(s);
    printf("%f\n",result);




}