
#include <stdio.h>
// Legnagyobb kozos oszto felhasznalasaval LKKT = a*b/LNKO
int main()
{
    int a, a1, b, b1, c;
    printf("Adjon meg két szamot:");
    scanf("%d %d", &a, &b);
    printf("A ket szam: a = %d b = %d \n\n", a, b);
    a1 = a;
    b1 = b;
    while (b1 != 0)
    {
        c = a1 % b1;
        a1 = b1;
        b1 = c;
    }

    printf(" A LNKO(%d, %d): %d \n", a, b, a1);
    printf(" A LKKT(%d, %d): %d\n", a, b, (a * b) / a1);
}