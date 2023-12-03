#include <stdio.h>

// tokeletes szam osztoik osszegevel.
int perfect(int a)
{
    int i = 1;
    int sum = 0;
    while (i < a)
    {
        if (a % i == 0)
        {
            sum = sum + i;
        }
        i++;
    }
    if(sum == a)
        return 1;
    return 0;
}

int main(void)
{
    int in = 6;
    int out = perfect(in);
    printf("%d\n", out); /* Ez nem feltétlenül szükséges,
        debug módban lehet figyelni out változó értékét. */
    return 0;
}
