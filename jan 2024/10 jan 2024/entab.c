#include <stdio.h>
#define tab_width 4

int c;

int spacecount=0;

int main(){

    while((c=getchar())!=EOF){
        if(c==' '){


            spacecount++;            
        }
        else{
            // If a non-space character is encountered
            if (spacecount > 0) {
                // Calculate tabs and spaces needed to replace consecutive spaces
                int tabs = spacecount / tab_width; // 3/4
                int spaces = spacecount % tab_width;//1

                // Replace consecutive spaces with tabs and spaces
                for (int i = 0; i < tabs; ++i) {
                    putchar('\t'); // Output tabs
                }
                for (int i = 0; i < spaces; ++i) {
                    putchar(' '); // Output remaining spaces
                }

                spacecount = 0; // Reset space count
            }

            putchar(c); // Output non-space character



        }
        
    




    }






}