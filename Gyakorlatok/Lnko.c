#include<stdio.h>

int main(){

    int a,b,c;
    while(scanf("%d%d",&a,&b)==2){
        while(b != 0){
            c = a % b;
            a = b;
            b = c;
            
        }
        printf("%d \n",a);

    }
    return 0;
}