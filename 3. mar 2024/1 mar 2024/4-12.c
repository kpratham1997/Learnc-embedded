//4-12
/*quick sort algo working
1- {5, 3, 7, 2, 8, 1, 6, 4}

First choose a pivot meaning center point for this array, it will be 2
//move the pivot value either to the far right or far left- we are chossing far left

2- {2, 3, 7, 5, 8, 1, 6, 4}

we find two things
a) Item from left -First item from the left section which is larger than our pivot value =2 that is 3
b) Item from right-First item from the right section which is smaller than our pivot value =2 that is 1

swap the itemfromleft with itemfromright 

3- {2, 1, 7, 5, 8, 3, 6, 4}

we repeat it until we get that itemfromleft (index) > itemfromright (index)

4- {2, 1, 7, 5, 8, 3, 6, 4} but we get the same value.

we swap item from right with our pivot

5-{1, 2, 7, 5, 8, 3, 6, 4}


left subarray sort

{1} -no sorting


right subarray sort

{7,5,8,3,6,4}

we will chose 8 as our pivot again. move it to the right this time as we want it on the end.

{8,5,7,3,6,4}

find item from left and item from right






*/


#include <stdio.h>

void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(int v[], int left, int right) { //qsort(arr, 0, n - 1);=qsort(arr, 0, 7); //{5, 3, 7, 2, 8, 1, 6, 4}
    int i, last;
    
    if (left >= right) /* do nothing if array contains fewer than two elements */// 0>=7
        return;
    
    swap(v, left, (left + right) / 2); /* move partition element */ //{2, 3, 7, 5, 8, 1, 6, 4}
    last = left; /* to v[0] */ 
    
    for (i = left + 1; i <= right; i++) { /* partition */ //left =0+1 =1 . right= keeps incrementing from 0 to 7
        if (v[i] < v[left])
            swap(v, ++last, i); 
    }
    //{2, 1, 7, 5, 8, 3, 6, 4} because v[5]<v[0]


    
    swap(v, left, last); //left =0 ,last=1 ={1, 2, 7, 5, 8, 3, 6, 4} 
    qsort(v, left, last - 1);//left=0,last=1-1= 0, right=0 (just after this function call)//left subarray sort
    qsort(v, last + 1, right);//last =1+1=2, right = 7, //right subarray sort 
}

int main() {
    int arr[] = {5, 3, 7, 2, 8, 1, 6, 4};


    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Size of array : %d\n",sizeof(arr));

    printf("Size of array : %d\n",sizeof(arr[0]));



    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    qsort(arr, 0, n - 1);
    
    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
