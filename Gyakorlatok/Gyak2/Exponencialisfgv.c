#include<stdio.h>

//euler fele szamot becsli meg 
int main(){
    int i = 1, n;
    double oszto = 1;
    double e = 1;
    printf("Irja be hanyadik kozelitesig akarja az e-t: ");
    scanf("%d",&n);
    double array[n];
    while(i < n){
        //faktorialist noveli es osztja el az egyet vele
        // és hozzáadja az előző értékhez 
        oszto = oszto * i;
        e =  e + (1/oszto);
        array[i-1] = e;
        printf("%0.20lf\n", array[i-1]);
        i++;
    }
   

    return 0;
}