#include <stdio.h>


//p start-5
//n -3
//input -110110110
//mask  -000111000 -you get this mask through shift invert shift
//output-110001110


void print_binary(unsigned num){

    if(num>1){

        print_binary(num/2);
    }
    printf("%u",num %2);



}


unsigned invert(unsigned x,int p,int n){

unsigned mask= ~(~0<<n) <<(p-n+1);

x=x^mask;

return x;

}


int main(){
    unsigned x=0b110110110;
    int p=5;
    int n=3;

    unsigned result =invert(x,p,n);

    printf("Orginal x: %u ",x);
    print_binary(x);
    printf("\n");
    printf("Modified x: %u ",result);
    print_binary(result);
    printf("\n");



}