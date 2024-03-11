#include <stdio.h>
#include <string.h>

int strindex(char s[],char t[]);


int main(){
    char s[]="Hello World!";
    char t[]="or";

    int position=strindex(s,t);

    if(position!=-1){

        printf("the rightmost occurence of  '%s' in '%s' is at position: %d\n",t,s,position);
        


    }else{

        printf("'%s' not found in '%s'\n",t,s);

    }




}

int strindex(char s[],char t[]){
    int i,j,k;
    int position=-1;
    for(i=0;s[i]!='\0';i++){
        for(j=i,k=0;t[k]!='\0' && s[j] == t[k];j++,k++){}
        
        
        
        if(t[k]=='\0'){
            position=i;
        }

    }


return position;

}