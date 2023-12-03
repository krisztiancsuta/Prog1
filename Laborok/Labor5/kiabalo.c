/*
Írj programot, mely a bemenetére érkező szöveget úgy írja ki a kimenetre,
hogy minden nagybetűvel kezdődő szót csupa nagybetűssé alakít, a
többit változatlanul hagyja. A bemenetre érkező szöveg szavait egyetlen
szóköz választja el megymástól. Az elvárt működést az alábbi példa demonstrálja:

Input:     ez EgY pElda A felaDat EGY lehetseges Bemenetere
Output:    ez EGY pElda A felaDat EGY lehetseges BEMENETERE
*/
#include <stdio.h>

char kiabal(char c)
{
    if ('a' <= c && c <= 'z')
        return c - ' ';
    else
        return c;
}

int main()
{
    char c;
    while (scanf("%c", &c) == 1)
    {
        if ('a' <= c && c <= 'z')
        {
            while (c != ' ')
            {
                printf("%c", c);
                if (scanf("%c", &c) != 1)
                    break;
            }
            printf(" ");
        }

        if ('A' <= c && c <= 'Z')
        {
            while (c != ' ')
            {
                char x = kiabal(c);
                printf("%c", x);
                if (scanf("%c", &c) != 1)
                    break;
            }
            printf(" ");
        }
    }

    return 0;
}