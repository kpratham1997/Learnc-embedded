#include <stdio.h>


int binsearch(int elementtofind ,int sortedArray[],int arraySize);

int main(){

int sortedArray[]={1,2,3,4,5,6,7,8,9,10};
int arraySize=sizeof(sortedArray)/sizeof(sortedArray[0]);

int elementtofind=8;

int result =binsearch(elementtofind,sortedArray,arraySize);

if(result!=-1){

    printf("Element %d found at index %d\n",elementtofind,result);
}
else{

    printf("Element %d not found\n", elementtofind);

}




}

int binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

       if(v[mid]==x){
        return mid;
         }

      low = (x < v[mid]) ? low : mid + 1;
      high = (x > v[mid]) ? high : mid - 1;


        
    }

    
}