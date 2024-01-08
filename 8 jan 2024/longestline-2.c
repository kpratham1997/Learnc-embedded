#include <stdio.h>


#define MAXLINE 1000




int getLine(char line[],int maxline);

void copy(char to[],char from[]);


int main(){
    size_t len; //this is current line length //made changes from int to size_t so it will automatically allocate for big sizes
    size_t max=0;//max line length which we will encounter
    char line[MAXLINE]; //this is the current line
    char longest[MAXLINE];//this is the longest line which we will encounter
    

    while((len=getLine(line, MAXLINE))>0){ //if the number of elements in the line (current) array is more than 0 
        if(len>max){                       //check if its value is greater than max value   
            max=len;                       //if the current value's length is greater than max value..make the current value as max value
            copy(longest,line);            //copy the elements of current line array to longest array
        }
    if(max>0){
        printf("Length of the longest character is %d\n", max );
        printf("the longest line is "); // printing the longest character
        printf("%s\n",longest);

    }
    
    }
return 0;
}


int getLine(char line[],int maxline){//function whicjh returns the number of elements of the current line array
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
void copy(char to[],char from[]){ //copying elements of one array to another
    
    int i=0;
    while((to[i]=from[i])!='\0'){//it will keep copying from the from[] array until it gets an EOF
        i++;

    }

}


