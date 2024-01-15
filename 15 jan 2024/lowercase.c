#include <stdio.h>

// convert c to lower case

int lower(int c){

    if(c>='A' && c<= 'Z'){

        return c + 'a' -'A';
    }
    else{

        return c;
    }



}

int main(){


    printf("%c\n",lower('C'));

}