#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void qsort_own(int *t, int size)
{
    if (size <= 1)
        return;
    int i = 0, j = size - 1;
    int pivot = 0;
    while (i < j)
    {
        while (i < size - 1 && t[i] <= t[pivot])
            i++;
        while (t[j] > t[pivot])
            j--;
        if (i < j)
            swap(t + i, t + j);
    }
    swap(t + pivot, t + i);

    qsort_own(t, j);
    qsort_own(t + j + 1, size - (j + 1));
}

void rendez1(int *t, int size) // selection_sort
{
    // keressuk meg a minimumot
    int i, j;
    for (i = 0; i < size - 1; ++i)
    {
        int iMin = i;
        for (j = i + 1; j < size; ++j)
        {
            if (t[j] < t[iMin])
                iMin = j;
        }
        swap(&t[i], &t[iMin]);
    }
}

void rendez2(int *t, int size) // insertion sort
{
    int i, j, k, f, s, a;
    for (i = 1; i < size; i++)

    {
        s = t[i];                  /* beszúrandó  elem */
        for (a = 0, f = i; a < f;) /* log keres és 0 i között */

        {
            k = (a + f) / 2;
            if (t[k] < s)
                a = k + 1;
            else
                f = k;
        }
        for (j = i; j > a; j--) /* résztömb húzása */
            t[j] = t[j - 1];
        t[a] = s; /* besz úrás */
    }
}

typedef double (*square)(double);


double integral(double a, double b, int n, double (*f)(double))
{
    double dx = fabs(b-a)/n;
    double x = a;
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum = sum + f(x) * dx;
        x = x + dx;
    }

    return sum;
}


typedef double (*ftrig)(double);

int main()
{
    ftrig f[3] = {sin,cos,tan};;


    printf("%f", integral(0,3.14,10000,sin));
    int t[] = {1, 2, 32, 43, 12, 23, 12, 3, 43, 23, 43};
    qsort_own(t, 11);
    for (int i = 0; i < 11; i++)
    {
        printf("%d ", t[i]);
    }
}