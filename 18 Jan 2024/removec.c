#include <stdio.h>

void squeeze(char s[],int c);

int main(){
char inputString[] = "Helloc, World!";
char characterToRemove = 'l';



squeeze(inputString,characterToRemove);

printf("%s\n",inputString);

}

void squeeze(char s[],int c)
{
    int i,j;
    for(i=j=0;s[i]!='\0';i++){ //iterate through all characters in a string
        if(s[i]!=c){
            s[j++]=s[i]; 
        }

    }
     s[j]='\0';



}