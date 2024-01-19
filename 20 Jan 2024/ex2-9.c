// count 1 bits in x faster


#include <stdio.h>

int bitcount(unsigned x){
    int b=0;
    for(;x;x&=(x-1)){

            b++;
        
    }
    return b;


}


int main(){
    unsigned a =bitcount(0b110110110u);
    printf("%u\n",a);



}
