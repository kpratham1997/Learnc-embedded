#include <stdio.h>
#include <string.h>

void reverse(char s[]){

    int i,j;

    char temp;
    for(i = 0 , j = strlen(s) - 1; i < j ; i++ ,j--){
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;

    }

}


void itob(int n,char s[],int b){
    if(b<2|| b>16){
        printf("base out of range");
        return;
    }

    int i=0;
    int sign=n;
    unsigned int num = ( n < 0 ) ? -n : n;

    do{
        int digit = num%b;
        s[i++]=(digit<10)? digit +'0' : digit- 10 + 'A';
        num /=b;
    }while(num>0);
    if(sign<0){
        s[i++]='-';

    }

    s[i]='\0';
    reverse(s);

}








int main(){
    int number=168;
    char string[20];
    int base=16;
    itob(number,string,base);
    printf("Converted number (base %d): %s\n", base, string);

}