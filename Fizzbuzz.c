#include <stdio.h>
 
int main(void) {
    for (int szam = 1; szam <= 20; szam = szam+1)
        if (szam % 3 == 0 && szam % 5 == 0)
            printf("fizzbuzz\n");
        else
            if (szam % 3 == 0)
                printf("fizz\n");
            else
                if (szam % 5 == 0)
                    printf("buzz\n");
                else
                    printf("%6d\n", szam);
 
    return 0;
}
