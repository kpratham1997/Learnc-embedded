#include <stdio.h>
#include <ctype.h>

int htoi(char s[]){
    int result =0;
    int i=0;

    if(s[0]=='0' && (s[1]== 'x' || s[1]=='X')){

        i=2;
    }




while(s[i] !='\0'){
    char currentChar=tolower(s[i]);

    if(isdigit(currentChar)){
        result =result*16 +(currentChar - '0');
    }else if(currentChar>= 'a' && currentChar <='f'){
        result=result*16 +(currentChar -'a'+10);
    }else{
        printf("%c\n",s[i]);

    }

    i++;
}
    return result;
}



int main(){
    char hexString1[] = "la";
    char hexString2[] = "Ox1F";
    char hexString3[] = "Ox28";

    printf("%s : %d \n",hexString1,htoi(hexString1));
    printf("%s : %d \n",hexString2,htoi(hexString2));
    printf("%s : %d \n",hexString3,htoi(hexString3));


}