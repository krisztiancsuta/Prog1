#include <stdio.h>

int ipow(int x, int n) // x*x*x*....*x
{
    int i = 1;
    int res = 1;
    if (n == 0)
        return 1;

    for (i = 0; i < n; i++)
    {
        res = res * x;
    }
    return res;
}

int main(void)
{

    int out = ipow(2, 4);
    printf("%d\n", out); /* Ez nem feltétlenül szükséges,
        debug módban lehet figyelni out változó értékét. */
    return 0;
}
