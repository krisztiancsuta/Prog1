#include <stdio.h>
#include <stdlib.h>

unsigned long long int factorial(unsigned long long int n)
{

    if (n > 0)
        return factorial(n - 1) * n;
    else
        return 1;
}
unsigned long long int fibonacci(unsigned long long int n)
{
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

void print_base_iter(unsigned n, unsigned base)
{
    unsigned d;
    for (d = 1; d * base <= n; d = d * base)
        ;

    while (d > 0)
    {
        printf("%d", (n / d) % base);
        d = d / base;
    }
}


int main()
{

    print_base_iter(20, 2);
}