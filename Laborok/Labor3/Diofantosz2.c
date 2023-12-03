#include <stdio.h>
/*
ax + by = c
x = (c - by)/a
y = (c - ax)/b

*/
int main()
{
    int a , b, c ;
    int x, y = 0;
    scanf("%d%d%d", &a, &b, &c);
    for (x = 1; x < c ; x++)
    {
        y = (c - a * x) / b;
        if(y <= 0)break;
        if(a * x + b * y == c){
            printf("%d %d\n",x,y);
        }
        
    }

    return 0;
}