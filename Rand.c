#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int dobas[12 - 2 + 1] = {0};

    srand(time(0));

    /* kísérletek */
    for (int i = 0; i < 1000; i += 1)
    {
        int kocka1 = rand() % 6 + 1; /* 1-6 */
        int kocka2 = rand() % 6 + 1;
        int osszeg = kocka1 + kocka2;
        dobas[osszeg - 2] += 1; /* 2-12 → 0-10 */
    }

    /* eredmény */
    for (int i = 2; i <= 12; i += 1)
    {
        printf("a+b=%2d: %3d alkalom\n", i, dobas[i - 2]); /* ! */
    }
}
