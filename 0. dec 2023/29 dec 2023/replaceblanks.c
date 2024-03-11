#include <stdio.h>


int main(){

    int p,c =EOF;


    while((c=getchar())!=EOF){

        if( c == ' ' && p == ' '){
            continue;
           
        }
        else{

            putchar(c);
            
        }

        p=c;
        
    
    }






}