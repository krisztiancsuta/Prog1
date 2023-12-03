/*
A lebegőpontos típus ábrázolási pontossága (machine precision, ε) a legkisebb 1.0-nál
nagyobb ábrázolható érték és az 1.0 különbsége. Pongyolán fogalmazva az 1.0-t
követő "következő valós szám" 1.0-től ε távol van.

Az ε érték csak a mantissza pontossága. A 8.0-t követő következő valós
szám 8 ε távolságra, az 1024-et követő következő valós szám 1024 ε távolságra
helyezkedik el.

Az IEEE 754 szabványos double típus mantisszája 52-bites, így e típus ε-ja
ε = 2-52≈2.2204E-16.

C-ben a különböző lebegőpontos típusok ε-ját eléred, ha beilleszted a
float.h fejlécfájlt:

#include <stdio.h>
#include <float.h>
int main()
{
    printf("%.10E\n", DBL_EPSILON);
    printf("%.10E\n", FLT_EPSILON);
    return 0;
}
Írj programot, mely beolvas egy double értéket a standard inputról, és kiírja a
 "következő double" tőle mért távolságát.

A megoldást aritmetikai úton keresd meg, nem használhatod a float.h-t!

Egy lehetséges algoritmus az alábbi:

Legyen a beolvasott érték a.
Legyen d=a.
Mindaddig, amíg a+d > a, oszd el d-t kettővel.
A következő double az utolsó a + d, amelyre még a feltétel teljesült.
A keresett távolság (a + d) - a formában megkapható. Vigyázz, ez nem feltétlen egyezik meg d-vel!
A program az eredményt %.5E formátumkóddal írja ki.

Amennyiben a bemenet értéke 0.0, semmit nem kell kiírnod.

*/
#include <stdio.h>
int main()
{
    double a, d;
    scanf("%lf", &a);
    d = a;
    while (a + d > a)
    {// A következő double az utolsó a + d, amelyre még a feltétel teljesült.
        d = d / 2;
    }
    double eps =   (a + 2*d)-a;
    if (a != 0)
    {
        printf("%.5E",eps);
    }

    return 0;
}
