#include <stdio.h>

void escape(char s[],char t[]){

    int i,j;
    for(i=j=0;t[i]!='\0';i++){
        switch (t[i])
        {
        case '\n':
            s[j++]='\\';
            s[j++]='n';
            /* code */
            break;
        case '\t':
            /* code */
            s[j++]='\\';
            s[j++]='t';
            break;
        default:
            s[j++]=t[i];
            break;
        }

    }


s[j]='\0';



}


void unescape(char s[] ,char t[]){
    int i,j;

    for(i=j=0;t[i]!='\0';i++){
        if(t[i]=='\\'){
            switch (t[++i])
            {
            case 'n':
               s[j++]='\n';
                break;
            case 't':
               s[j++]='\t';
                break;
            default:
                s[j++]='\\';
                s[j++]=t[i];

                break;
            }

        }
        else{
            s[j++]=t[i];

        }



    }

s[j]='\0';

}







int main(){

    char original[] ="Hello\n\tWorld";
    char escaped[100],unescaped[100];

    escape(escaped,original);
    printf("Original : %s\n",original);
    printf("Escaped : %s\n",escaped);

    unescape(unescaped,escaped);
    printf("Unescaped %s\n",unescaped);

}