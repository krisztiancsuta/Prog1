#include<stdlib.h>
#include<stdio.h>

char *concatenate(char *str1, char *str2)
{
    char *name;
    char i, j;
    for (i = 0; str1[i] != '\0'; i++)
        ; // str1 length
    for (j = 0; str2[j] != '\0'; j++)
        ; // str2 length

    name = (char *)malloc(j + i + 2);

    for (i = 0; str1[i] != '\0'; i++)
    {
        name[i] = str1[i];
    }
    
    name[i] = ' ';
    i++;
    for (j = 0; str2[j] != '\0'; j++, i++)
    {
        name[i] = str2[j];
    }
    name[i] = '\0';

    return name;
}

int main(){
   char *str =  concatenate("Lengyel", "Ibolya");
    printf("%s",str);
    
   free(str); 
   return 0;

}