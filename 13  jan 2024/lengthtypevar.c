#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){

    printf("Range of char : %d to %d\n",CHAR_MIN, CHAR_MAX);
    printf("Range of unsigned char : 0 to %u\n",UCHAR_MAX);
    
    printf("Range of short : %d to %d\n",SHRT_MIN,SHRT_MAX);
    printf("Range of unsigned : 0 to %u\n",USHRT_MAX);

    printf("Range of int : %d to %d\n",INT_MIN, INT_MAX);
    printf("Range of unsigned int : 0 to %u\n",UINT_MAX);
    
    printf("Range of long : %ld to %ld\n",LONG_MIN,LONG_MAX);
    printf("Range of unsigned long : 0 to %lu\n",ULONG_MAX);
    


}