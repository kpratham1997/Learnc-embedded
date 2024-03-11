#include <stdio.h>



void swap(int *px,int *py){
    int temp=*px;
    *px=*py;
    *py=temp;


}

int main(){
    int a=10,b=5;
    printf("a before swap: %d\n",a);
    printf("b before swap: %d\n",b);

    swap(&a,&b);

    printf("a before swap: %d\n",a);
    printf("b before swap: %d\n",b);


    
}