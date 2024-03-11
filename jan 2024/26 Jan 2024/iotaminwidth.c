#include <stdio.h>
#include <string.h>

void reverse(char s[]){
    int i,j;
    char temp;
    for(i=0,j=strlen(s)-1; i<j;i++,j--){

        temp= s[i];
        s[i]=s[j];
        s[j]=temp;


    }



}


void itoa(int n,char s[],int min_width){

    int i=0;
    int sign =n;
    unsigned int num =(n<0)?-n:n;

    do{
        s[i++]=num%10+'0';
    }while((num/=10)>0);

    if(sign<0){
        s[i++]='-';
    }

    while(i<min_width){
        s[i++]=' ';
    }

s[i]='\0';
reverse(s);



}




int main(){
    int number=-12345;
    char string[20];
    int min_width =14;
    itoa(number,string,min_width);
    printf("%d: %s\n",min_width,string);



}