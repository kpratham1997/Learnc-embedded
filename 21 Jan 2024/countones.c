// count 1 bits in x


#include <stdio.h>

int bitcount(unsigned x){
    int b;
    for(b=0;x!=0;x>>=1){
        if(x&01){

            b++;
            

        }
    }
    return b;


}


int main(){
    int a=bitcount(0b110110110);
    printf("%d",a);



}

