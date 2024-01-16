#include <stdio.h>

//convert string to int


int strtoint(char s[]){
    int i,n;
    n=0;
    for(i=0;s[i]>='0' && s[i]<='9';i++){
        n=10*n+(s[i]-'0');
    }
    return n;



}

int main(){

    printf("%d\n",strtoint("67890"));
   


}