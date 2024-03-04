//4-14 macros

#include <stdio.h>

#define swapx(t,x,y) do{ t temp =x; x=y; y=temp; }while(0)

int main(){
    int a=5, b=10;
    printf("Before swapping: a = %d, b = %d\n", a, b);
    swapx(int ,a, b);
    printf("After swapping: a = %d, b = %d\n", a, b);

    double c=3.14, d=6.28;
    printf("Before swapping: c = %.2f, d = %.2f\n", c, d);
    swapx(double ,c, d);
    printf("After swapping: c = %d, d = %d\n", c, d);



}