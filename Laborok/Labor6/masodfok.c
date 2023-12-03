#include<stdio.h>
#include<math.h>
int masodfoku(double a, double b, double c, double *p1, double *p2)
{

    double d = b * b - 4.0 * a * c;

    if (d >= 0)
    {
        *p1 = (-b + sqrt(d)) / (2.0 * a);
        *p2 = (-b - sqrt(d)) / (2.0 * a);
        return 2;
    }
    return 0;
}

int main(void)
{
    double x1, x2;
    int n = masodfoku(1, 2, 1, &x1, &x2);
    printf("%d",n);
    printf("%f %f",x1,x2);
    return 0;
}
