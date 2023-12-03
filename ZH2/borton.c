#include<stdio.h>

int jail(int tomb[])
{
    int i = 0, j = 9;
    int cnt = 0;
    while (i < j)
    {
        if (tomb[j] != 0)
        {
            if (tomb[i] != 10)
            {
                tomb[i]++;
                tomb[j]--;
                
                if (i % 2 != j % 2)
                    cnt++;
            }
            else
                i++;
        }
        else
            j--;
    }
    return cnt;
}

int main()
{

    int tomb[10] = {10,10,10,8,7,8,3,2,4,1};

    int cnt = jail(&tomb[0]);
    printf("%d",cnt);
}