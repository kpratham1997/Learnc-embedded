#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[],int maxline);
void reversestring(char line[],int len);
int c;


int main(){
    
    int len;
    char line[MAXLINE];
    
     while ((len = getLine(line, MAXLINE)) > 0) {
        reversestring(line, len);
        printf("%s\n", line);
    }




}


void reversestring(char line[],int len){
    int start =0;
    int end =len-1;

    while(start<end){
        char temp= line[start];
        line[start]=line[end];
        line[end]=temp;

        start++;
        end--;


    }



}

int getLine(char line[],int maxline){//function which returns the number of elements of the current line array
    int c,i; 
    for (i=0;i < maxline -1 && (c=getchar())!=EOF && c!='\n';i++){//if its less than max limit or not EOF or not a new line.keep writting elements in array.
        line[i]=c;

    }
    if(c=='\n'){  //if its a newline. write the newline in the array and then increment
        line[i]=c;
        i++;

    }

    line[i]='\0'; // after the conditional loop, create an EOF and return the number of elements
    return i;

}
