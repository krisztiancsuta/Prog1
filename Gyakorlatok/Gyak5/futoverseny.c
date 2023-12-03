/*
Futóverseny
Írjunk programot egy futóversenyhez, amely
minden induló csapat legjobb versenyzőjének időeredményét írja ki!

A versenyen 50 csapat indul.
A célba ért futók pontos száma a standard inputon érkezik első adatként.
Ezután kettesével (szóközzel elválasztva, egész számokkal) érkeznek a
célba ért futók adatai. A két adat: a futó csapatának száma (1-től számozzuk őket) és
az eredménye másodpercben.
A programnak ki kell írnia a legjobb eredményt azoknál a csapatoknál,
amikből legalább egy futó célba ért.
*/

#include <stdio.h>
// beerkezo adat 1 csapat 3.84 ido
int main()
{
    //input a csapasztam ido: 11 2.32
    int rajtszam[50] = {0};//szamolom hany befuto volt 
    double legjobbido[50];// feljegyzem a beerkezo csapatok ideet
    int csptszam,n;
    double ido;
    printf("Beerkezett futok szama:");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%lf", &csptszam,&ido);//megnezzuk volt e mar eredmeny
        if (legjobbido[csptszam-1] > 0)
        {
            if(ido < legjobbido[csptszam-1]){
                legjobbido[csptszam-1] = ido;
            }
        }else{
            legjobbido[csptszam-1] = ido;
            rajtszam[csptszam-1]++;//novelem a beerkezett futok szama alapjan csapatokra bontva 
        }
    }
    for (int i = 0; i < 50; i++)
    {
        if(rajtszam[i] != 0){
            printf("A legjobb eredmeny a %d csapatban: %0.3f masodperc volt.\n",i+1,legjobbido[i]);
        }
    }
    

    return 0;
}