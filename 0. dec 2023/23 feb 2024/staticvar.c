#include <stdio.h>


void increment_counter(){
    static int count =0;
    
    count++;

    printf("%d\n",count);

}




int main(){

    increment_counter();

    increment_counter();

    increment_counter();




}