#include <stdio.h>


//Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions.
//n=2
//x=110110110

//output=101101101


//first right shift x by n
//then create a mask for 3 values at the end and invert its value
//then shift thw bits to the start and combine them using OR


#include <stdio.h>


void print_binary(unsigned num){

    if(num>1){
       print_binary(num/2);
    }
    printf("%u", num % 2);


}

/* rightrot: rotate x to the right by n bit positions */
unsigned rightrot(unsigned x, int n) {
    unsigned rbit; /* rightmost bit */

    rbit = x << (sizeof(unsigned) * 8 - n);
    x = x >> n;
    x = x | rbit;

    return x;
}



int main(void) {
    unsigned x =(unsigned)284;
    int n=3;
    printf("%u ",x);
    print_binary(x);
    printf("\n");

    unsigned result=(unsigned)rightrot(x, n);
    printf("%u ",result);
    print_binary(result);
    printf("\n");
    return 0;
}

