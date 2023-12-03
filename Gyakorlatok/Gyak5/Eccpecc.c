#include <stdio.h>
/*Ecc, pecc, kimehetsz
10 óvodás kiszámolóst játszik. Körbeállnak,
majd sorban minden n-ediket kiszámolnak a körből,
amíg csak egy marad. Írjunk programot,
mely n beolvasása után kiírja,
hogy milyen sorrendben esnek
ki az ovisok a játékból
*/
int main(void)
{
    int ovodasok[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int i, j, s = -1;
    int n = 10; // ecc pecc kimehetsz mondoka szotagjainak szamat adja meg
    // ennyi kell leszamolni minden emberrol, de ha ovodasok[10] tombben
    // van 0 tehat mar kiesett akkor ugrani kell a sorszaman ugy hogy ne
    // haladjunk a mondoka szotagjaival
    for (i = 0; i < 10; i++) // 10 ovodasig szamol el/ 10 kort jatszunk le
    {
        for (j = 0; j < n; j++) // a mondoka szotagjait tartja szamon
        {
            do
            {
                s = (s + 1) % 10;   // erteke 0,1,2,3,4...9 lehet tehat az ovodasokat tartja szamon
            } while (!ovodasok[s]); // ovodasok indexe !=0 ha 1 akkor befejezi a ciklust es lep a
                                    // mondokaval
        }
        printf("%d korben kiesett a %d. ovodas.\n", i + 1, s + 1);
        ovodasok[s] = 0; // kiesette nyilvanitom az s edik ovodast
    }

    return 0;
}