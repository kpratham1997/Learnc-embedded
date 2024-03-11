#include <stdio.h>

#define TOTAL_CHARS 128 

int main() {
  int charFrequency[TOTAL_CHARS];  
 

    for(int i=0;i<TOTAL_CHARS;i++){
        charFrequency[i]=0;
        printf("%d",charFrequency[i]);

    }

     int c;
    while((c=getchar())!=EOF){
        if (c>0 && c <=128){
            charFrequency[c]++;
        }

    }


    printf("Charactere\tFrequency\tStars\n");
    for (int i=0; i<TOTAL_CHARS;i++){
        if (charFrequency[i]>0){

            printf("%c\t%d\t",i,charFrequency[i]);
            for(int j=0;j<charFrequency[i];j++){


                printf("*");
            }
            printf("\n");

        }


    }


  
}
