#include <stdio.h>

int is_vowel(char a)
{
    if (a >= 'A' && a <= 'Z')
        a = a + ' ';
    char vowels[5] = {'a', 'e', 'o', 'u', 'i'};
    for (int i = 0; i < 5; i++)
    {
        if (a == vowels[i])
            return 1;
    }

    return 0;
}

int main(void)
{
    char a;
    scanf("%c", &a);
    int db = is_vowel(a);
    printf("%d", db);

    return 0;
}