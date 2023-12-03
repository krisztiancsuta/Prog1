#include <stdlib.h>
#include <stdio.h>

void swap(double *a, double *b){
    double temp = *b;
    *b = *a;
    *a = temp; 
}


void own_qsort(double *tomb, int size){
    int i = 0;
    int j = size;
    double pivot = tomb[size/2];
    while(i < j){
        if(tomb[i] < pivot){
            i++;
        }else{
            j--;
            if(tomb[j] <= pivot){
                swap(tomb + i,tomb + j);
            }
        }
    }
    if(i > 1){
        own_qsort(tomb, i);
    }
    if(size-i -1 > 1){
        own_qsort(tomb + i, size - i - 1);
    }
}

int main(){
    double tomb[10] = {3,4 ,2, 1, 5, 6, 8,7, 9, 10};

    own_qsort(tomb,10);
    for(int i = 0; i < 10; i++){
        printf("%lf \n", tomb[i]);
    }
    return 0;

}