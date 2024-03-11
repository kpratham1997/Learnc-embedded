#include <stdio.h>

#define MAXLINES 1000


int main(){
    int c;
    int len=0;
    char line[MAXLINES]; //this is the current line

    //line length should be more than 0 for it to print


    while((c=getchar())!=EOF){
            if(!(c==' ' || c== '\t' || c=='\n')){
                    line[len]=c;
                    len++;
                    putchar(c);
   

            } 
            
    
    }


}

    

