#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    if (a != 1 && a != 0)
    {
        for (int i = 0; i < a; i++)
        {
            printf("x");
            if (i != 0 && i != a - 1)
            {
                for (int k = 0; k < a - 2; k++)
                {
                    printf(".");
                }
            }
            else
                for (int j = 0; j < a - 2; j++)
                    printf("x");
            printf("x\n");
        }
    }else printf("x");
    

    return 0;
}