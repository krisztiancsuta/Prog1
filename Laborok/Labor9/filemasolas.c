#include <stdlib.h>
#include <stdio.h>



int main(){
    FILE *p = fopen("numbers.txt","r");
    if(p == NULL)
        return 1;

    FILE *p2 = fopen("positive_numbers.txt","w");
    double num;

    while(fscanf(p,"%lf",&num)==1){
        if(num >= 0)
            fprintf(p2,"%0.4f ",num);
    }
    fclose(p);
    fclose(p2);


    return 0;
}