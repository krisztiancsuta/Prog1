#include <stdio.h>

char cserel(char c)
{
    if ('a' <= c && c <= 'z')
        return c - ' ';
    else if ('A' <= c && c <= 'Z')
        return c + ' ';
    else
        return c;
}

int main()
{
    char c;
    while (scanf("%c", &c) == 1)
    {
        char x = cserel(c);
        printf("%c", x);
    }

    return 0;
}