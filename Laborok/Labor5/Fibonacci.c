#include <stdio.h>
#include<limits.h>
/*
-----
Test case #1
input = 0 1
-----
Your standard output:
94
Correct standard output:
93

-----
Test case #2
input = 1 1
-----
Your standard output:
93
Correct standard output:
92

-----
Test case #3
input = 2 0
-----
OK

-----
Test case #4
input = 18446744073709551615 18446744073709551615
-----
Your standard output:
2
Correct standard output:
1

-----
Test case #5 (random test)
input = 2046960810 846122988
-----
OK


At least one of the tests failed.*/
typedef long long unsigned int nagy; // 64 bites szam
int main()
{
    nagy tomb[100];
    int i = 2;

    scanf("%llu%llu", &tomb[0], &tomb[1]);

    for (i = 2; i < 100; i++)
    {
        tomb[i] = tomb[i - 1] + tomb[i - 2];
        if (tomb[i] < tomb[i-1] )
        {
            break;
        }
        
    }
    printf("%d\n", i-1);

    return 0;
}