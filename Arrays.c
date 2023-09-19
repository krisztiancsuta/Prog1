#include <stdio.h>

int main(void)
{
    int array[11];
    int array2[11];
    int sztabla[100];
    int paros[50], paratlan[50];
    for (int i = 1; i <= 10; i++)
    {
        int k = 1;
        array[i] = i;
        for (int j = 1; j <= 10; j++)
        {
            array2[j] = j;
            // printf("%4d",array[i] * array2[j]);
            sztabla[k] = array[i] * array2[j];
            printf("%4d", sztabla[k]);
            
            k++;
        }
        printf("\n");
       
    }

    return 0;
}