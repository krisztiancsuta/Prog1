#include<stdio.h>
//egesz szam faktorialisa
int main(){
    int n,i;
    printf("Kerek egy szamot:");
    scanf("%d",&n);
    int faktorialis = 0;
    for ( i = 1; i <= n; i++)
    {
        int faktorialis = faktorialis * i;
        printf(" %d * ",i);
        if(i == n){
            printf("A szam faktorialisa:  %d ",faktorialis);
        }
        
    }
    
}