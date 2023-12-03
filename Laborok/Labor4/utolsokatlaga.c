/*
Írj programot, mely valós számokat olvas a standard inputról,
amíg csak tud, majd kiírja a standard outputra az utoljára beolvasott 10 szám átlagát.
Amennyiben a bemeneten kevesebb mint 10 szám érkezik, a program azok átlagát írja ki.
Biztos lehetsz benne, hogy a bemeneten legkevesebb egy valós szám érkezik.

A megoldáshoz alkalmazd a ciklikus indexelést! (3. előadás, Tömbös algoritmusok videó)

Az eredményt 3 tizedesre kerekítve írd ki! (%.3f)
*/
#include <stdio.h>

int main()
{
    double tomb[10];
    double szam;
    double osszeg = 0.0;
    int db = 0;
    while (scanf("%lf", &tomb[db % 10]) == 1)
        db++;
    for (int i = 0; i < 10; i++)
    {
        osszeg = osszeg + tomb[i];
    }
    if (db > 10)
        db = 10;
    printf("%0.3f ", osszeg / db);

    return 0;
}
