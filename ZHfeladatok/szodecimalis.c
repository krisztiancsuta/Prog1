#include<stdio.h>
void copy_nth_words(char *str1, char *str2, int n)
{
    int j;
    int i;
    int k = 0;
    int szavak = 0;
    int hol = 0;
    for (i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] == ' ' || str1[i+1]=='\0')
        {
            if( str1[i+1]=='\0')
                i++;
           
            if (szavak % n == 0)
            {
                for (j = 0; j < i - hol; j++)
                {
                    str2[k + j] = str1[hol + j];
                }
                k = k + j;
            }
            hol = i;
            szavak++;
        }
    }
}
int main()
{
    char str1[] = "cica hollo varju kutya mokus beka csiga";
    char str2[20];
    copy_nth_words(&str1[0], &str2[0], 3);
    printf("%s",str2);
    return 0;
}