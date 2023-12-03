#include <stdio.h>
#define false 0
#define true !false
/*
Írjunk programot, amely beolvas 5 egész számot, és kiírja a beolvasott számok közül a legnagyobbat!
Írjunk programot, amely egész számokat olvas be, és kiírja az összegüket. A beolvasást akkor hagyja abba, ha 0 érkezett!
Írjunk programot, amely egész számokat olvas be, majd kiírja az átlagukat és azt, hogy hány páros szám volt köztük. A beolvasást akkor hagyja abba, ha 0 érkezett!
Írjunk programot, amely száz darab egész számot olvas be, és kiírja, hogy hányadik elem volt a legnagyobb.
*/
//Elso feladat legnagyobb kereses
/*
int main(void){
    int szamok[5] = { 1,2,3,4,5};
    int legnagyobb = 1;

    for (int i = 0; i < 5; i++){
        scanf("%d",&szamok[i]);
        printf(" A szam: %d\n", szamok[i]);
    }
    
    int i = 0;
    while(i < 4 ){
        if(szamok[i] < szamok[i + 1]){
            szamok[i] = szamok[i + 1];
        }else{
             szamok[i + 1] = szamok[i];
        }
        i++;
    }
    printf("A legnagyobb szam: %d ",szamok[i]);

    return 0;
}
*/
/*
int main(void){
    int max, a;
    scanf("%d",&max);
    for (int i = 1; i < 5; i++)
    {
        scanf("%d",&a);
        if(a > max){
            max = a;
        }
    }
    printf("%d",max);
    return 0;
}
*/


int main(void){
    int i = 0;
    int osszeg = 0;
    int feltetel = true;
    while(feltetel){
        int szamok[i + 1];
        scanf("%d",&szamok[i]);
        osszeg = szamok[i] + osszeg;
        if((szamok[i]) == 0)feltetel = false;
        i++;
    }
    printf("A szamok osszege: %3d\n", osszeg);

    return 0;
}
/*
int main(void){
    int sum = 0;
    int a;
    while(1){

        scanf("%d",&a);
        if(a == 0)
            break;
        sum = sum + a;
    }
    printf("%d",sum);
    return 0;
}
*/

/* Harmadik feladat
int main(void)
{
    int i = 0;
    int szamlalo = -1;
    double osszeg = 0;
    int feltetel = true;
    double atlag;
    while (feltetel)
    {
        int szamok[i];
        scanf("%d", &szamok[i]);
        osszeg = szamok[i] + osszeg;
        atlag = osszeg / i;
        if ((szamok[i]) == 0)
            feltetel = false;
        if(szamok[i] % 2 == 0)
            szamlalo++;
        i++;
    }
    printf("A szamok atlaga: %0.3lf es %d db paros szam volt koztuk.\n", atlag, szamlalo);

    return 0;
}
*/
/* Negyedik feladat
int main(void)
{
    int i, max, a, maxindex;
    for (i = 0; i < 100; i++)
    {
        scanf("%d", &a);
        if (i == 0)
        {
            maxindex = 0;
            max = a;
        }
        else if (a > max){
            maxindex = i;
            max = a;
        }
        printf("%d", maxindex);
    }
    return 0;
}
*/

/* Gyökkeresős
int main(void){
    double a = 0, b = 2, eps = 0.0001;

    while(b-a > eps){
        double f = (a+b)/2;
        int n = 2;
        if(f*f-2 < 0){
            a = f;
        }else
            b = f;

    }
    printf("%f",a);

    return 0;
}
*/
/* euler szam kereso
int main(void)
{
    double e = 1.0;
    int k;
    int fakt = 1;
    for (k = 1; k <= 13; k++)
    {
        fakt = fakt * k;
        e = e + (1.0 / fakt);
    }

    printf("%f", e);

    return 0;
}
*/