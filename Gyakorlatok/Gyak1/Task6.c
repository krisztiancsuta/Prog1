#include<stdio.h>
#define false = 0;
#define true = !false;
int main(void){
    int n,q = 2,maradek;
    scanf("%d",&n);
    while(q < n){
        maradek = n % q;
        if (maradek == 0){
            printf("%d ",q);
        }
        q = q + 1;
    }
}