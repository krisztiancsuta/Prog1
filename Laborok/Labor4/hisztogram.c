
/*
Írj programot, mely érdemjegyeket olvas be a standard inputról, majd kiírja,
hogy melyik jegyből hány darab született! A jegyek szóközzel vannak egymástól elválasztva.
Nincs végjel, egészen a bemenet végéig kell olvasni.

A 3 2 3 1 5 2 3 1 5 bemenet hatására az program az alábbi összegzést írja a standard outputra:

5: 2 db
4: 0 db
3: 3 db
2: 2 db
1: 2 db
Feltételezheted, hogy a bemeneten nem érkeznek 1-nél kisebb vagy 5-nél nagyobb számok. A megoldásban tilos a switch vagy if kulcsszavak használata.

*/
#include <stdio.h>

int main()
{
    int hanydb[5] = {0};
    int a;//bemenet
    while(scanf("%d",&a)==1)
        hanydb[a-1]++;
    for (int i = 5; i > 0; i--)
    {
        printf("%d: %d db\n",i,hanydb[i-1]);
    }
    
    

    return 0;
}
