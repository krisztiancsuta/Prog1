#include <stdio.h>
#include <stdlib.h>

/*
4 // hany sor van meg
123 12:35 0 //
444 15:22 1
567 11:22 0
123 12:38 1
*/
typedef struct time
{
    int perc;
    int sec;
} time;

typedef struct train
{
    int id;
    time date; // 14:32
    int start; // 0 vagy 1
} train;

train *read(char *fname, int *size)
{
    char line[100];
    int s;
    FILE *fp = fopen(fname, "r");
    fgets(&line[0], 100, fp);
    sscanf(&line[0], "%d", &s);
    *size = s;

    train *tomb = (train *)malloc(s*sizeof(train));
    int i = 0;
    while (fgets(&line[0], 100, fp) != NULL)
    {
        train temp;
        sscanf(&line[0], "%d %d:%d %d", &temp.id, &temp.date.perc, &temp.date.sec, &temp.start);
        tomb[i] = temp;
        i++;
    }
    fclose(fp);
    return tomb;
}

int nterminal(train *tomb, int size)
{

    train temp;
    int n = 0;
    int cnt = 0;
    for (int i = 0; i < size; i++)
    {
        n = 0;
        temp = tomb[i];
        n = n + temp.start;
        for (int j = 1 + i; j < size; j++)
        {
            if (tomb[j].id == temp.id)
            {
                n = n + tomb[j].start;
            }
        }
        
        if (tomb[0].start != 1 && n  % 2 == 0)
        {
            cnt++;
        }
        
    }
    return cnt;
}

int main()
{

    int size;
    char fname[30] = "test.txt";
    train *tomb = read(&fname[0], &size);
    printf("%d\n",nterminal(tomb, size));
    for (int i = 0; i < size; i++)
    {
        printf("%d %d:%d %d\n", tomb[i].id, tomb[i].date.perc, tomb[i].date.sec, tomb[i].start);
    }

   

    free(tomb);
    return 0;
}