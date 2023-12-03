#include <stdio.h>

int main()
{
    int kategoria, fizetes;
    scanf("%d %d", &kategoria, &fizetes);

    switch (kategoria)
    {
    case 0:
    
        printf("Bonus: 0 EUR");
        break;
    case 1:
        printf("Bonus: 1000 EUR");
        break;
    case 2:
        printf("Bonus: %d EUR", (int)(fizetes * 0.1));
        break;
    case 3:
        printf("Bonus: %d EUR", (int)(fizetes * 0.1 + 1000));
        return 0;
    default:
        printf("INVALID\n");
        printf("Bonus: 0 EUR");
        break;
    }
    return 0;
}