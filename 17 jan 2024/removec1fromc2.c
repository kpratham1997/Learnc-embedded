#include <stdio.h>

int any(char s1[],char s2[]){
    
    int i,j;


    for(i=0;s1[i] !='\0';i++){
        for(j=0;s2[j] != '\0'; j++){
                if(s1[i]==s2[j]){

                    return i;

                }

        }

    }

return -1;


}


int main(){
    char str1[] = "Hello, World!";
    char str2[] = "aeiou";

    int result = any(str1, str2);

    if (result != -1) {
        printf("First location where a character from s2 occurs: %d\n", result);
    } else {
        printf("No characters from s2 found in s1.\n");
    }
   


}