/*
A Kolakoski-sorozat 1-esekből és 2-esekből álló végtelen számsorozat, melynek első néhány eleme

1 2 2 1 1 2 1 2 2 1 2 2 1 1 ...

A sorozat érdekes tulajdonsága, hogy ha felírjuk az egymás mellett álló azonos számjegyekből álló blokkok hosszúságait,
akkor magát a Kolakoski-sorozatot kapjuk vissza.
1 (2 2) (1 1) (2) (1) (2 2) (1) (2 2) (1 1) ...
1  2     2     1   1   2     1   2     2 . . .
Az általánosított Kolakoski-sorozat n különböző számjegyet tartalmaz, úgy, hogy 1-esek blokkját 2-esek blokkja,
azt 3-asok blokkja, stb követi, és a fenti tulajdonságot megőrzi. n=4-re pl. az alábbi sorozatot kapjuk:

1  2 2  3 3  4 4 4  1 1 1  2 2 2 2  3 3 3 3 ...
1  2    2    3      3      4        4
1 22 33 444 111 222 3333 4444 1111 2222 3 4411222333444111122223333444412233444111222333344441111222234411222333444
Írj programot, mely beolvassa n értékét, melyről tudjuk, hogy 2 és 9 közé esik. A program listázza ki az
általánosított Kolakoski-sorozat első 100 tagját! A számokat egyetlen szóköz válassza el!

*/
#include <stdio.h>
int main()
{

    int t2[110] = {1, 2, 2};
    int x = 1;
    int k = 0;
    int i = 0;
    int n =0;
    scanf("%d",&n);
    while (i<101)
    {
        for (int a = 0; a < t2[k]; a++)
        {
            for (int b = 0; b < t2[x]; b++)
            {
                if (i == 101)
                        break;
                if (x % n == 0)
                {
                    t2[i] = n;
                    printf("%d ", n);
                }
                else
                {
                    t2[i] = x % n;
                    if (i != 1)
                    {
                        printf("%d ", x % n);
                    }
                    
                }
                
                i++;
                
            }
            x++;
        }
        k++;
    }

    return 0;
}