#include <stdio.h>

void print_binary(unsigned num){
   
    if(num>1){

        print_binary(num/2);
    }

    printf("%u",num %2 );



}
//first create mask for clearing bits
//then clear the specific bits
//take right most n bits from var y and store it into a var
//shift it so it can take the place of the replaced bits
// Now do or operation with the cleared bit and shifted bit


unsigned int setbits(unsigned x,int p,int n,unsigned y){ // x=110110110
    unsigned mask  =~(~0<<n) << (p-n+1); //00000111 << 3 = 000111000 

    //~mask= // 111000111
    x=x & ~mask;//110110110 & 111000111 =110000110 

    unsigned bits_from_y = y & ~(~0<<n);//100 & 000000111=000000100

    bits_from_y =bits_from_y << (p-n+1);//000000100<< (3) =000100000
    return x | bits_from_y;//110000110 | 000100000 =110100110
    
}



int main(){


    unsigned x = 0b110110110;
    int p=5;
    int n=3;
    unsigned y=0b100;


    unsigned result = setbits(x,p,n,y);


    printf("Original x: %u ", x);
    print_binary(x);
    printf("\n");

    printf("Start pos in x: %d\n ", p);
    printf("End pos in x: %d\n ", p+n);
 
    printf("Change in x which is y : %u ", y);
    print_binary(y);
    printf("\n");
    printf("Modified x: %u ", result);
    print_binary(result);
    printf("\n");



}