
#include <stdio.h>
// Legnagyobb közös osztó
int main()
{
    int a, b, c;
    printf("Adjon meg két szamot:");
    scanf("%d %d", &a, &b);
    printf("A ket szam: a = %d b = %d \n", a, b);
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    printf(" A LNKO: %d", a);
}