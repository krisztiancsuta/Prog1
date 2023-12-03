#include <stdio.h>
#include<math.h>
/*

*p hozzaferest kapok a p pointerben levo cimhez
 olvashato es irhato
*/

void xchg(int x, int y)
{
    int tmp = x;
    x = y;
    y = tmp;
    // nem cserel
}

void xchgp(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
    // csereli az eredeti valtozokat
}

int gyok(double x, double *res)
{
    // ha x kisebb 0 nal akkor gyok(x) nem ertelmezheto
    //  ha nem kisebb akkor a doublet cimet tartalmazo
    //  *res pointerben beirom az eredmenyt
    if (x < 0.0)
        return 0;
    *res = sqrt(x);
    return 1;
}

int *elso_negativ(int *t, int meret)
{
    for (int i = 0; i < meret; i++)
    {
        if (t[i] < 0) // *(p+i) is jo
        {
            return t+i;
        }
    }
    return NULL;
}

int main(void)
{
    int t[] = {2, 3, 35, -6, 4, 2, 23};
    
    for (int i = 0; i < 7; i++)
    {
        printf("%d\n", t[i]);
        int a = 1;
        int *p2 ;
        p2 = &a;
        
        int *px = elso_negativ(t, 7); // t = &t[0] kezdocim
        printf("%p\n", px);
        printf("%p\n", px + 1);
        printf("%p\n", px + 2);
        printf("%d", *p2);
        return 0;
    }
}
