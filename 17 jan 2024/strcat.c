#include <stdio.h>

void custConcat(char s[],char t[]){
    int i,j;
    i=j=0;


    while(s[i] != '\0'){
        i++;
    }
    while((s[i++]=t[j++]) !='\0'){

        ;
    }


}

int main(){
 char str1[50]="Hello";
 char str2[] =" World";

    custConcat(str1,str2);
    printf("%s\n", str1);
}