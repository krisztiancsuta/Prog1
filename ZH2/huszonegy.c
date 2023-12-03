
#include <stdio.h>

int a(int *tomb)
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        if (tomb[i] == 1)
            sum = sum + i;
    }

    return sum;
}

void b(int *tomb, int *maradek, int *veszelyes)
{
    int m = 0;
    for (int i = 0; i < 10; i++)
    {
        if (tomb[i] == 0)
            m++;
    }
    *maradek = m;
    int v = 0;
    int sum = a(tomb);
    for (int i = 0; i < 10; i++)
    {
        if (tomb[i] == 0 && sum + i > 21)
            v++;
    }
    *veszelyes = v;
}

int main()
{
    int lap;
    int maradek;
    int veszelyes;
    int t[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    scanf("%d", &lap);
    t[lap] = 1;
    b(t,&maradek,&veszelyes);
    while ( maradek > veszelyes)
    {
        scanf("%d", &lap);
        t[lap] = 1;
        if(a(t) == 21)
            printf("WIN");
        b(t,&maradek,&veszelyes);
    }
    if(a(t) > 21)
        printf("LOSE");
    else if(maradek == veszelyes && a(t) != 21)
        printf("WIN");


    return 0;
}
