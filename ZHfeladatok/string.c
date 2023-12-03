
#include <stdio.h>

void mail_merge(char *str1, char *str2, char *str3)
{
    // str1
    int i = 0;
    int j = 0;
    int k = 0;
    for (i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] == '#')
        {
            for (j = 0; str2[j] != '\0'; j++)
            {
                str3[k + j] = str2[j];
            }
            k = k + (j - 1);
        }
        else
        {
            str3[k] = str1[i];
        }
        k++;
    }
    str3[k] = '\0';
}

int main(void)
{
    char str1[] = "Oh #, miert vagy te #?";
    char str2[] = "Julia";
    char str3[60];
    mail_merge(str1, str2, str3);
    printf("%s", str3);
    return 0;
}