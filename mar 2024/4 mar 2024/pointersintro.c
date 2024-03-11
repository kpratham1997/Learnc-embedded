#include <stdio.h>


int main(){
    
    int x=1,y=2,z[10];
    int *ip; // which means ip can store memory adress of int value.

    ip = &x;
    y = *ip;
    *ip = 0;
    ip = &z[0];

    *ip = *ip + 10;
    printf("z[0]=%d\n",z[0]);

    y = *ip + 1;
    printf("y=%d\n",y);

    ++*ip;
    printf("z[0]=%d\n",z[0]);

    int *iq;
    iq=ip;
    printf("z[0] via iq= %d\n",*iq);

    printf("%p\n",ip);
    printf("%p\n",++ip);

    return 0;
}