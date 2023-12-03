
#include<stdio.h>
typedef struct
{
    int y;
    int m;
    int d;
} date;

int is_leap_year(int y)
{
    // 100 al oszthato akkor nem, csak ha 4 el vagy 400 al
    return (y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0)); // ha 400 al vagy 4 el oszthato de nem oszthato 100 al
}

int day_of_year(date d)
{
    int sum = d.d;
    int honapok[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(d.y))
    {
        honapok[1]++;
    }
    for (int i = 0; i < d.m - 1; i++)
    {
        sum += honapok[i];
    }
    return sum;
}
int datecmp(date d1, date d2)
{
    if (d1.y > d2.y)
        return 1;
    if (d1.y < d2.y)
        return -1;
    if (d1.m > d2.m)
        return 1;
    if (d1.m < d2.m)
        return -1;
    return d1.d - d2.d;
}
void date_swap(date *d1, date *d2)
{
    date tmp = *d1;
    *d1 = *d2;
    *d2 = tmp;
}

int days_between(date d1, date d2)
{
    if (datecmp(d1, d2) > 0)
    {
        date_swap(&d1,&d2);
    }
    int x = day_of_year(d2) - day_of_year(d1);
    for (int i = d1.y ; i < d2.y; i++)
    {
        x += is_leap_year(i) ? 366 : 365;
    }
    return x;
}

int main()
{
    date d1 = {2003,6,2};
    date d2 = {2053,6,2};
    printf("%d",days_between(d1,d2));

    return 0;
}