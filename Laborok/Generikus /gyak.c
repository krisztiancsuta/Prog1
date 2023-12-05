#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int tomb[5];

int (*f(void))[5] // visszaad egy int tombre mutato pointert
{
    return &tomb;
}

double (*g(int sw))(double)
{
    if (sw)
    {
        return sin;
    }
    else
    {
        return cos;
    }
}
/*
.....(*(*f(void)(void)(void))) ....
{
    return f;// onmagat visszaado fuggveny
}
*/

typedef double (*fvptr)(double);
// fvptr tipus  ... double (*)(double) neve
typedef double (*gfvptr)(double, double, double, double);

typedef double (*hfvptr)(double, double, fvptr);

double root(fvptr f, double a, double b, double eps, hfvptr h)
{
    while (b - a > eps)
    {
        // double c = (a + b) / 2; // itt akarok altalonsitani fv-t
        // sdouble c = g(a,b,fa,fb);
        double c = h(a, b, f);
        if (f(c) > 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
    return a;
}

double s(double a, double b, double fa, double fb)
{
    // haromszog hasonlosagos gyokkereses
}

double plus(double a, double b)
{
    return a + b;
}

double times(double a, double b)
{
    return a * b;
}

double max(double a, double b)
{
    if (a > b)
        return a;
    return b;
}

double gen_acc(double t[], int size, double (*f)(double, double), double init)
{
    double a = init;
    for (int i = 0; i < size; i++)
    {
        a = f(a, t[i]);
    }
    return a;
}

void kiir(int t[], int n, void (*ki)(int))
{
    int i;
    for (i = 0; i < n; i++)
    {
        ki(t[i]);
    }
}

void p(int s)
{
    printf("%d ", s);
}

void q(int s)
{
    for (int i = 0; i < s; i++)
    {
        putc('*', stdout);
    }
    putc('\n', stdout);
}

int main()
{

    (*f())[2] = 7;

    printf("%f\n", g(1)(0.5)); //
    //------------------------------
    kiir((int[]){1, 2, 3, 4, 5}, 5, p);
    kiir((int[]){1, 2, 3, 4, 5}, 5, q);

    gen_acc((double[]){1.0, 2.0, 3.0, 4.0, 5.0}, 5, plus, 0);
    printf("%f\n", gen_acc((double[]){1.0, 2.0, 3.0, 4.0, 5.0}, 5, times, 1));
    printf("%f\n", gen_acc((double[]){1.0, 310, 3.0, 4.0, 5.0}, 5, max, 0));

    // double z = root(sin, -0.5, 0.5, 0.000000001);

    // printf("%f\n", z);
    return 0;
}