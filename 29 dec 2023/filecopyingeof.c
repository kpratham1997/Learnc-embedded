#include <stdio.h>


int main(){

    int c;
    printf("%d",EOF);
    while((c=getchar)!= EOF){
        putchar(c);
    }
    
    printf("%d",(getchar()!=EOF));
    return 0;
}