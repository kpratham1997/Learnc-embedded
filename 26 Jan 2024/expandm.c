#include <stdio.h>
#include <ctype.h>


void expand(char s1[ ],char s2[ ]){
    int i=0,j=0;
    
    if(s1[i]=='-'){
        s2[j++]='-';
        i++;
    }

    while(s1[i]!='\0'){
        if(s1[i] == '-' && s1[i+1] != '\0' && s1[i+1] != '-'){

            char start =s1[i-1];
            char end=s1[i+1];


            if ((isdigit(start) && isdigit(end)) || (isalpha(start) && isalpha(end) && start <= end)) {
                for (char c = start + 1; c < end; c++) {
                    s2[j++] = c;
                }


             } else {

                s2[j++] = s1[i];
                s2[j++] = s1[i+1];
            }
            i+=2;
        }else{

            s2[j++] = s1[i++];

        }
        i++;
    }

    if (j > 0 && s2[j-1] == '-') {
        s2[j++] = '-';
    }
    s2[j]='\0';

}



int main(){
    char s1[]="-a-z O-9";
    char s2[100];

    expand(s1,s2);
    printf("%s\n",s2);


}