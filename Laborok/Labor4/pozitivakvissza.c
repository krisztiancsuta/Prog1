/*
Írj programot, mely egész értéket olvas a bemenetről,
és ezek közül a pozitívokat fordított sorrendben kiírja!
Az adatsor végjele a 0 érték, legfeljebb 100 darab érték érkezhet
(a végjel előtt).

Például: 2 -1 5 -7 -1 8 -3 0 -> 8 5 2
*/

#include <stdio.h>

int main()
{
    int tomb[100];
    int szam, i = 0;
    scanf("%d", &szam);
    while (szam != 0)
    {
        if (szam > 0)
            tomb[i++] = szam;
        scanf("%d", &szam);
    }
    while (i > 0){
        i--;
        printf("%d ",tomb[i]);
        
    }
        
    return 0;
}