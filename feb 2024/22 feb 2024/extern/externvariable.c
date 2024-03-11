#include <stdio.h>

int var= 123;

int secondarymain();

int main(){

    
    printf("number inside main function: %d\n",var);

    var=456;

    secondarymain();

}