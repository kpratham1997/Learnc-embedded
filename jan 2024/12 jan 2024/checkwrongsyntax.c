#include <stdio.h>

#define MAX_LENGTH 1000

int check_syntax();

int main(){

    printf("Enter the C program to check syntax:\n ");

    if(check_syntax()){

        printf("No syntax error found");

    } else{

        printf("syntax error found");


    }


}


int check_syntax(){

  char stack[1000];
  int top=0;
  char c;
  int insidequote=0;
  int escaped=0;


  while((c=getchar())!=EOF){
        if(!insidequote){
            if(c=='(' || c =='{' || c=='['){
                stack[top++]=c;
            }
            else if(c==')'|| c=='}'||c==']'){
                if(top==0 || (c == ')'&& stack[--top]!='(') || (c==']' && stack[--top]!='[') || (c=='}' && stack[--top]!= '{')){

                    return 0;
                }

            }else if(c=='\"'){
                insidequote=1;


            }else if(c=='\''){
                insidequote=2;


            }
        
       } else{

        if(escaped){

            escaped=0;


        }
        else if(c=='\\'){

            escaped=1;
        }
        else if((c=='\"' && insidequote==1) || (c=='\'' && insidequote==2)){
            insidequote=0;

        }


    }
}
return (top == 0) ? 1 : 0;

}
















