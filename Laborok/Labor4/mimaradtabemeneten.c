
/*
Írj programot, mely a standard inputról valós számokat olvas mindaddig,
amíg tud. A program írja ki a standard outputra a beolvasott számok összegét
három tizedesjegy pontossággal.
Ezt követően új sorba írja ki, hogy az utolsó valós szám beolvasása után
mi maradt a standard inputon.
Ha a program egy számot sem tud beolvasni, akkor az összeg 0.000 legyen.

A program elvárt működését az alábbi példák mutatják:


    Input:   1.0 2.0 3.0alma korte szilva
    Output:  6.000
             alma korte szilva

    Input:   1e-3 -2e-3 bolha 3e-8
    Output:  -0.001
             bolha 3e-8
*/
#include <stdio.h>

int main()
{

    double a, sum = 0;
    char c;
    while (scanf("%lf", &a) == 1)
        sum += a;
    printf("%0.3f\n", sum);
    while (scanf("%c", &c) == 1)
        printf("%c", c);

    return 0;
}