// 1000 nel kevesebb karakter
// a vegjel # a karakter sorozat utan
// szavak jonnek és egy szokoz valasztja el oket
// lapra legfeljebb s sor és n karakter kerulhet
/*
aaa bbb#
aaa\nbbb#
ez is jon bemeneten
s = 2 sor n = 3 karakter
aaa
bbb
   */
/*
s = 2
n = 9
Alma''alma\npiros''alma''es''korte#

Alma alma\n //9karakter
piros\n //5karakter

alma es korte# //13 karakter marad
*/

/*
elmegy n ig és kicserel ha ' ' van ott
ha ez nem teljesul a prevet kicsereli es onnan kezdi a szamolast n ig */
#include <stdio.h>

int main()
{
    char data[1000];
    char c;
    int j = 0, i = 0;

    while (scanf("%c", &c) == 1)
    {
        if (c == '#')
            break;
        data[i] = c;
        i++;
    }

    int s, n;
    scanf("%d %d", &s, &n);
    int prev = 0;
    int prev2 = 0;
    int rakott = 0;
    int scnt = 0;
    while (scnt < s)
    {
        for (j = prev; j <= n + prev; j++)
        {
            if (j % n == 0 && data[j] == ' ' && j != 0)
            {
                data[j] = '\n';
                prev = j;
                rakott = 1;
                scnt++;
            }
            else if (data[j] == ' ' && j != 0)
            {
                prev2 = j;
                rakott = 0;
            }
        }
        if (rakott == 0)
        {
            data[prev2] = '\n';
            prev = prev2;
            scnt++;
        }
        rakott = 0;
    }

    i = 0;
    int cnt = 0;
    while (data[i] != '\0')
    {
        cnt++;

        if (data[i] == '\n')
            cnt = 0;

        i++;
    }
    printf("%d\n", cnt-s+1);
    printf("%s\n", data);
    return 0;
}