#include <stdio.h>


#define MAXLINE 1000




int getLine(char line[],int maxline);



int main(){
    size_t len; //this is current line length //made changes from int to size_t so it will automatically allocate for big sizes
    char line[MAXLINE]; //this is the current line

    while((len=getLine(line, MAXLINE))>0){ //if the number of elements in the line (current) array is more than 0 
        if(len>80){ 
            printf("%s",line);                   
        
         }
    
    }
return 0;
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