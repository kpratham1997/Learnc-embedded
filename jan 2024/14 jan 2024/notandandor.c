#include <stdio.h>


int main(){
    int i,c;
    int lim=100;
    char s[lim];

    for(i=0;i<lim-1;i++){
        c=getchar();
        if(c=='\n'){
            break;

        }

        if(c==EOF){
            break;

        }
        s[i]=c;
        putchar(s[i]);



    }






}