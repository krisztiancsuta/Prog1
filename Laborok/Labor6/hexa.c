#include <stdio.h>

int hexa_value(char a)
{
    int res = 0;

    if (a >= '0' && a <= '9')
    {
        return a - '0';
    }
    if (a >= 'a' && a <= 'z')
        a = a - ' ';
    if (a >= 'A' && a <= 'F')
    {
        return 10 + a - 'A';
    }
    return -1;
}
//((a*16)+a)*16)+a)*16
int main(void)
{
    char a;
    int elozo = 0;
    int eredmeny = 0;

    int i = 0;
    while (scanf("%c", &a) == 1)
    {

        eredmeny = eredmeny * 16 + hexa_value(a);
    }
    printf("%d", eredmeny);
    return 0;
}