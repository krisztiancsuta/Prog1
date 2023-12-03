#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int iscapital(char a)
{
    if ('A' <= a && a <= 'Z')
        return 1;
    return 0;
}

char **string_select(char **str, int meret, int *size)
{
    int cnt = 0;
    int meretek[100];
    for (int i = 0; i < meret; i++)
    {
        if (iscapital(str[i][0]))
        {
            meretek[cnt] = strlen(str[i]) + 1;
            cnt++;
        }
    }
    char **res = (char **)malloc(cnt * sizeof(char *));
    for(int i = 0; i < cnt; i++){
        *(res + i) = (char *)malloc(meretek[i]);
    }
    *size = cnt;
    int j = 0;
    for (int i = 0; i < meret; i++)
    {
        
        if (iscapital(str[i][0]))
        {
           strcpy(res[j++],str[i]);
            
        }
    }

    return res;


}

int main() {
    char *str[] = {"alma", "korte", "Alma", "Korte"};
    int meret;
    char **res = string_select(str, 4, &meret);

    printf("Méret: %d\n", meret);
    for (int i = 0; i < meret; i++) {
        printf("%s\n", res[i]);
        free(res[i]);
    }
    free(res);
    return 0;
}

//maxtrynumber = 100000;setInterval(function(){docheck()},10);