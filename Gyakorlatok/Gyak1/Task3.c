#include<stdio.h>

int main(){
    int n;
    printf("Adjon meg egy szamot:");
    scanf("%d",&n);
    printf("A sorozat elso n eleme.\n");
    int sum = 1;
    for ( int i = 0; i < n; i++)
    {
        sum = sum + i;
        printf(" %d ",sum);
    }
    
}