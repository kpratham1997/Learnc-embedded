#include <stdio.h>


void removeComments();

int main(){

    printf("Enter the text with comments to remove: \n");
    removeComments();
}

void removeComments(){
    int c,nextChar;
    int insideComment=0;
    int insideString=0;
    int insideChar=0;


    while((c=getchar())!=EOF){
        if(insideComment == 1){
            if(c=='*' && (nextChar=getchar())== '/' )
                    insideComment=0;

        }
        else if(insideString ==1){
            putchar(c);
            if(c=='\"' && !insideChar){
                insideString=0;

            }
        

        }else if(insideChar==1){
            putchar(c);
            if(c=='\'' && !insideString){
                insideChar=0;


            }


        }
        else{
            if(c=='/' && (nextChar=getchar())=='*'){
                insideComment =1;


            }
            else if(c=='\"'){
                putchar(c);
                insideString=1;




            }
            else if(c=='\''){
                putchar(c);
                insideChar=1;



            }
            else{
                putchar(c);


            }









        }





    }






}

