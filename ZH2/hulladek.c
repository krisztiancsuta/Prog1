#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    enum
    {
        ALTALANOS,
        EPITESI
    } tipus;
    double tartalom;
} kontener;

int atrendez(kontener *kontenerek, int size)
{
    int i = 0, j = size-1;
    int cnt = 0;

    for (i = 0; i < j ; i++)
    {
        j = size-1;
        double maradek;
        while (kontenerek[i].tartalom != 0)
        {
            if(i == j)
                break;
            if (kontenerek[i].tipus == kontenerek[j].tipus || (kontenerek[i].tipus == EPITESI && kontenerek[j].tipus == ALTALANOS))
            {
                double hianyzo = 10.0 - kontenerek[j].tartalom;
                if (hianyzo == 0)
                {
                    j--;
                }
                else
                {
                    maradek = kontenerek[i].tartalom - hianyzo;
                    if (maradek > 0)
                    {
                        kontenerek[j].tartalom += hianyzo;
                        kontenerek[i].tartalom = maradek;
                    }
                    else
                    {
                        kontenerek[j].tartalom += kontenerek[i].tartalom;
                        kontenerek[i].tartalom = 0.0;
                        cnt++;
                    }
                }
            }
            else
                j--;
        }
    }
    return cnt;
}

int main(){
    kontener t[5] = {{ALTALANOS,7.2},{EPITESI,3.00},{EPITESI,8.1},{ALTALANOS,2.1},{EPITESI,1.2}};

    int cnt = atrendez(t,5);
    for(int i = 0; i < 5; i++)
        printf("%d %lf\n",t[i].tipus,t[i].tartalom);
    printf("%d",cnt);


    return 0;
}

