#include <stdio.h>
typedef struct imperial
{
    int foot; // 1 foot = 12 inch
    int inch;
} imperial;
// 1 foot = 0.3048m
double imperial_to_metric(imperial data)
{
    double res;
    res = data.foot * 0.3048 + (data.inch / 12.0) * 0.3048;
    return res;
}

imperial plus( imperial x1,  imperial x2)
{
     imperial res = {x1.foot + x2.foot, x1.inch + x2.inch};
    if (res.inch >= 12)
    {
        res.inch = res.inch % 12;
        res.foot++;
    }
    return res;
}
int main(void)
{
     imperial data1;
    
    while(scanf("%d %d",&data1.foot ,&data1.inch) == 2)
    {
        printf("%.4f",imperial_to_metric(data1));
        printf(" ");
    }

    return 0;
}
