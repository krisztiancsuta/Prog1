
#include <stdlib.h>
#include <stdio.h>

int *filter_average(int *t, int size, int *n)
{
    int *p;
    double mean = 0;

    for (int i = 0; i < size; i++)
    {
        mean += t[i];
    }
    mean /= size;
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (mean > t[i])
        {
            j++;
        }
    }
    *n = j;
    p = (int *)malloc(j*sizeof(int));

    for (int i = 0, j = 0; i < size; i++)
    {
        if (mean > t[i])
        {
            p[j] = t[i];
            j++;
        }
    }

    return p;
}

int main()
{
    int t[2] = {1 ,2};
    int n;
    int *p = filter_average(t, 2, &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", p[i]);
    }

    free(p);
    return 0;
}