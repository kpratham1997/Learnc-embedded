#include <stdio.h>
#include <string.h>

int trim(char s[]){
    int n;
    for(n=strlen(s)-1;n>=0;n--){

        if(s[n]!=' ' && s[n]!='\t' && s[n]!='\n' ){
            break;

        }
    }
    s[n+1]='\0';
    return n;

}

int main(){

    char str[] ="Hello World        \t\n";
    int index=trim(str);
    printf("Trimmed String: \"%s\"\n",str);
    printf("Index of non space character : %d\n",index);






}