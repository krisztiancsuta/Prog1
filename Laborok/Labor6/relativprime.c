#include <stdio.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int relative_primes(int a, int b) // x*x*x*....*x
{
    if (gcd(a, b) == 1)
        return 1;
    return 0;
}

int main(void)
{
    int a, i=0;
    int db = 0;
    int tomb[10];
    while (scanf("%d",&a)==1)
    {
        tomb[i++] = a;
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (relative_primes(tomb[i], tomb[j]))
            {
                db++;
            }
        }
    }
    printf("%d", db);

    return 0;
}