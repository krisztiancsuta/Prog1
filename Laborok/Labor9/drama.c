#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
BÁNK
    Elárultattam?

TIBORC
    Én Tiborc vagyok, kegyes nagyúr - no, lám!

BÁNK
    Tiborc - (Gondolkodva járkál).

TIBORC
    Igen - mert szólni kellenék
    Nagy dolgokat -

BÁNK
    Melindáról?

TIBORC
    Nem arról.

BÁNK
    Nem!

TIBORC
    Lopni jöttem ide; mivel a szegény
    Anya s gyermekek velem - (Elfojtódik.)

BÁNK
    No jól van - úgy.

*/
char *trim(char *str)
{

    int i = 0;
    for (i = 0; str[i] != '\0' && str[i] != '\n' && str[i] != '.'; i++)
        ;

    str[i] = '\0';
    return str;
}

void capitalise(char *str)
{
    for (int i = 0; str[i] != '.'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - ' ';
    }
}
int main()
{

    char fileName[30];
    char name[20];
    char line[102]; //\0,\n
    char data[102];
    char format[] = ".txt";
    scanf("%s%s", fileName, name);
   //printf("%s\n%s", fileName, name);

    FILE *p = fopen(fileName, "r");
    if (p == NULL)
        return 0;
    strcat(name, format);
    FILE *p2 = fopen(name, "w");

    capitalise(name);
    while (fgets(line, 102, p) != NULL)
    {

        if (strcmp(trim(line), trim(name)) == 0)
        {
            do
            {
                fgets(line, 102, p);
                fprintf(p2, "%s", line + 1);
            } while (line[0] != '\n');
            fprintf(p2, "\n");
        }
    }

    fclose(p2);
    fclose(p);
    return 0;
}