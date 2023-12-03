/*
Írj programot, mely kiírja a standard outputra a standard inputon érkező
legnagyobb negatív és legkisebb pozitív számot. A standard inputon white space
 karakterekkel elválasztott egész számok érkeznek végjel nélkül.
 A program addig olvasson, amíg csak tud. Ha a bemeneten nem érkezik az
 adott feltételnek megfelelő szám (pl. nem jön egy pozitív sem), a
 program a kimenetre --- jelet írjon. Az elvárt kimenetet az alábbi példák demonstrálják:


    Input:  2 4 -3 1 -5 8
    Output: -3 1

    Input:  22 0 5 4 7
    Output: --- 4

    Input:  0
    Output: --- ---
    */

#include <stdio.h>
/*
int main()
{
    int a, p = 0, n = 0, k = 0;
    int maxNegativ, minPozitiv;
    maxNegativ = INT_MIN;
    minPozitiv = INT_MAX;
    while (scanf("%d", &a) == 1)
    {

        if (a < minPozitiv && a > 0)
        {
            minPozitiv = a;
            p++;
        }

        if (a > maxNegativ && a < 0)
        {
            maxNegativ = a;
            n++;
        }
        k++;
    }

    if (n == 0 && p != 0)
        printf("--- %d", minPozitiv);
    if (n != 0 && p == 0)
        printf("%d ---", maxNegativ);
    if (p != 0 && n != 0)
    {
        printf("%d %d", maxNegativ, minPozitiv);
    }

    if (minPozitiv == INT_MAX && maxNegativ == INT_MIN && k == 2)
        printf("%d %d", maxNegativ, minPozitiv);
    else if (n == 0 && p == 0)
        printf("--- ---");

    return 0;
}
*/
int main()
{
    int voltnegativ = 0, max;
    int voltpozitiv = 0, min;
    int a;
    while (scanf("%d", &a) == 1)
    {
        if (a < 0 && (!voltnegativ || a > max))
        {
            max = a;
            voltnegativ = 1;
        }
        if (a > 0 && (!voltpozitiv || a < min))
        {
            min = a;
            voltpozitiv = 1;
        }
    }
    if (voltnegativ && voltpozitiv)
    {
        printf("%d %d",max,min);
    }
    else if (voltnegativ)
    {
        printf("%d ", max);
        printf("---");
    }else if(voltpozitiv)
    {
        printf("--- ");
        printf("%d",min);
    }else
        printf("--- ---");
    
    

    return 0;
}
