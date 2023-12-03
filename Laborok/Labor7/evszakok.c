#include <stdio.h>
enum season
{
    SPRING,
    SUMMER,
    AUTUMN,
    WINTER
};

void print_season(enum season evszak)
{
    switch (evszak)
    {
    case SPRING:
        printf("spring ");
        break;
    case SUMMER:
        printf("summer ");
        break;
    case AUTUMN:
        printf("autumn ");
        break;
    case WINTER:
        printf("winter ");
        break;
    default:
        break;
    }
}
// 1 2  3 4 5 tavasz  6 7 8 nyar 9 10 11 osz   12
enum season month2season(int m)
{
    if (m == 12 || m == 1 || m == 2)
        return WINTER;
    if (m == 6 || m == 7 || m == 8)
        return SUMMER;
    if (m == 3 || m == 4 || m == 5)
        return SPRING;
    if (m == 9 || m == 10 || m == 11)
        return AUTUMN;
}

int main()
{
    int m;
    while (scanf("%d", &m) == 1)
    {
        print_season(month2season(m));
        printf(" ");
    }

    return 0;
}