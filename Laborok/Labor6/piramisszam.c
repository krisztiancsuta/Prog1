#include <stdio.h>

int pyramid(int n)
{
    int i = 1;
    int sum = 0;
    while (i <= n)
    {
        sum = sum + i * i;
        i++;
    }

    return sum;
}

int main(void)
{
    int in = 3;
    int out = pyramid(in);
    printf("%d\n", out); /* Ez nem feltétlenül szükséges,
        debug módban lehet figyelni out változó értékét. */
    return 0;
}
