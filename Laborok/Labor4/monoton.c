/*
Írj programot, mely a bemeneten érkező egészekből álló számsorozatból addig írja a
kimenetre a számokat, ameddig a sorozat szigorúan monoton
(akár szigorúan monoton növekvő, akár szigorúan monoton csökkenő)!

Például: 2 4 5 8 6 5 7 4 -> 2 4 5 8

Figyelj arra, hogy a programnak működnie kell akkor is,
ha a bemenet egyelemű vagy akár üres.

Például: 2 -> 2

A bemenet végét a scanf visszatérési értékével tudod figyelni.
*/
#include <stdio.h>

int main()
{
    int dir = 0;
    int a, previous;
    int n = 0; // hany darab szam volt eddig
    while (scanf("%d", &a) == 1)
    {
        n++;
        if (n == 2)
        {
            if (a > previous)
            {
                dir = 1;
            }
            else if (a < previous)
            {
                dir = -1;
            }else break;
        }
        else if (n > 2)
            if (dir == 1 && a <= previous || dir == -1 && a >= previous)
                break;

        printf("%d ", a);
        previous = a;
    }

    return 0;
}