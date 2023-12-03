#include <stdio.h>
#include <math.h>
/*
Írjunk programot, amely beolvas 5 egész számot, és kiírja a beolvasott számok közül a legnagyobbat!
Írjunk programot, amely egész számokat olvas be, és kiírja az összegüket. A beolvasást akkor hagyja abba, ha 0 érkezett!
Írjunk programot, amely egész számokat olvas be, majd kiírja az átlagukat és azt,
hogy hány páros szám volt köztük. A beolvasást akkor hagyja abba, ha 0 érkezett!
Írjunk programot, amely száz darab egész számot olvas be, és kiírja, hogy hányadik elem volt a legnagyobb.
*/
/*
int main()
{

    double a = 0, b = 2, eps;
    int n = 2;
    scanf("%lf", &eps);
    while (b - a > eps)
    {
        double c = (a + b) / 2;
        if (pow(c, n) - 2 < 0)
        {
            a = c;
        }
        else
            b = c;
    }
    printf("%f", a);

    return 0;
}
int main()
{
    // e = SUM(1/n!)
    int n;
    double e = 0;
    long long int fakt = 1;
    scanf("%d", &n);
    for (int i = 1; i < 10; i++)
    {
        e = e + 1 / (double)fakt;
        fakt = fakt * i;
    }
    printf("%0.10f", e);

    return 0;
}
int main()
{
    int a, max;
    scanf("%d", &max);
    for (int i = 1; i < 5; i++)
    {
        scanf("%d", &a);
        if (a > max)
        {
            max = a;
        }
    }
    printf("%d", max);

    return 0;
}

int main(){
    int a;
    int sum = 0;
    while(1){
        scanf("%d",&a);
        sum = sum + a;
        if(a == 0)break;
    }
    printf("\n%3d",sum);

    return 0;
}

int main()
{
    int a, i = 0, n = 1;
    double atlag = 0, sum = 0;
    while (1)
    {
        scanf("%d", &a);

        if (a == 0)
            break;

        sum = sum + a;
        atlag = sum / n;

        if (a % 2 == 0)
            i++;

        n++;
    }
    printf("Atlag: %0.2f \nParos szamok: %3d\n", atlag, i);

    return 0;
}
*/
int main(){
    int a,max = 0,i = 1, k = 1;
    while ((scanf("%d",&a) == 1))
    {
        if(a > max){
            max = a;
            i = k;
        }
        k++;
    }
    printf("%d",i);


    return 0;
}