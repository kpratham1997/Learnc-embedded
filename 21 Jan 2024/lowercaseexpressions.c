#include <stdio.h>


int lower(int c){

    return (c>='A' && c<='Z')? c +'a' -'A' : c; 

}







int main(){

    int upperCase ='G';
    int lowercase=lower(upperCase);
    printf("%c\n",lowercase);




}


