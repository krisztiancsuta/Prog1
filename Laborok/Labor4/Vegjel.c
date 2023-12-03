/*
Írj programot, mely egész számokat olvas a bemenetről egészen addig,
amíg 0 nem érkezik – ez jelzi a bemenet végét. 
Ekkor számítsa ki a program, és írja ki két tizedesjegy pontossággal a 
számok átlagát!

Például: 2 4 5 1 2 0 -> 2.80*/
#include<stdio.h>

int main(){

    int a,sum = 0, n = 0;
    
    scanf("%d",&a);
    while(a != 0){
        sum = sum + a;
        scanf("%d",&a);
        n++;

    }
    printf("%0.2f",sum/(double)n);

    return 0;
}