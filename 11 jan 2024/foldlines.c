#include <stdio.h>
#define MAX_LINE_LENGTH 1000 // Maximum input line length

void foldLongLines(char line[], int maxLength);

int getLine(char line[],int maxLineLength);



int main(){
    int n=20; 
    char line[MAX_LINE_LENGTH];

    printf("Enter lines of text (Ctrl+D to exit):\n");

    while(getLine(line,MAX_LINE_LENGTH)>0){
        foldLongLines(line,n);
        printf("%s",line);


    }

}

void foldLongLines(char line[], int maxLength) {
    int i, lastSpace;

    for (i = 0, lastSpace = -1; line[i] != '\0'; i++) {
        if (line[i] == ' ' || line[i] == '\t') {
            lastSpace = i; // Update last space/tab position
        }

        if (i >= maxLength && lastSpace != -1) {
            line[lastSpace] = '\n'; // Insert newline at the last space/tab
            i = lastSpace; // Move i back to last space/tab position
            lastSpace = -1; // Reset last space/tab position
        }
    }
}


int getLine(char line[],int maxLineLength){
int c,i;

for(i=0; i < maxLineLength-1 && (c=getchar())!=EOF && c!= '\n';i++){
    line[i]=c;

}

if (c=='\n'){
    line[i]=c;
    i++;
}

line[i]='\0';
return i;



}



