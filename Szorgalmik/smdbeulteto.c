/*

1.fej (0,0) rol indul
2.elmegy a szalagokhoz (-500, 300*i) i[1,2,3,4,5]
           ribbon      container
Load 0.1s  szalag      tarolo
L           1           0    //felvetel 1 szalagrol -> 0as taroloba rak
L           4           1
L           4           2
Place 0.1s  x           y       tarolo
P           1200        800     2
P           1400        1300    1
P           1600        900     0

0,0 bol elmegy -500,300*1 be berakja tarolo[0]ba
-500,300 bol elmegy -500,300*4 be (ami x2-x1,y2-y1)=v(0,900)szalag[4] -> tarolo[1]
-500,1200 bol felszed megint szalag[4] -> tarolo[2]

-500,1200 bol elindul (1200, 800) ba v(1200-(-500),800-1200)=max(1700,-400)

t1(felvetel es beultetes) = 0,1s
t2(x y iranyban mindig a nagyobb szamot nezzuk)=max(x,y)/5000s

Mik kellenek?

*/
#include <stdio.h>

typedef struct
{
    int x;
    int y;
} koord;

koord kulonbseg(koord poz1, koord poz2)
{
    koord dv;
    dv.x = poz2.x - poz1.x;
    dv.y = poz2.y - poz1.y;
    return dv;
}

void maximum(koord dv, int *result)
{
    if (dv.x < 0)
    {
        dv.x = -dv.x;
    }
    if (dv.y < 0)
    {
        dv.y = -dv.y;
    }

    if (dv.x > dv.y)
    {
        *result = dv.x;
    }
    else
        *result = dv.y;
}

void time(int maximum, double *result)
{
    *result = maximum / (double)5000;
}
int main()
{
    int max;
    double reszido;
    int ribbon_cnt[5] = {0};
    // ide irom mindig a mennyit kell a motornak mennie
    double osszido;
    // ide irom mennyi az ehhez szukseges ido
    koord poz1, poz2;
    poz1.x = 0;
    poz1.y = 0;

    int a, b; // a ribbon, b container
    char status;
    while (scanf("%c", &status)==1)
    {
        if (status == 'L')
        {
            osszido += 0.1;
            scanf("%d %d\n", &a, &b);

            ribbon_cnt[a - 1]++; // 1 es szalagot a-1 indexen tarol
            //container[b]++;
            poz2.x = -500;
            poz2.y = 300 * a;
            maximum(kulonbseg(poz1, poz2), &max);
            
            time(max, &reszido);
            printf("%f \n",reszido);
            osszido += reszido;
            poz1.x = poz2.x;
            poz1.y = poz2.y;
           
        }
        else if (status == 'P')
        {
            osszido += 0.1;
            scanf("%d %d %d\n", &poz2.x, &poz2.y, &b);

            maximum(kulonbseg(poz1, poz2), &max);
            
            time(max, &reszido);
            osszido += reszido;
            poz1.x = poz2.x;
            poz1.y = poz2.y;
            
        }
    }
    printf("Assembly time: %.2f s\n",osszido);
    printf("Part usage\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\tTape %d: %d\n", i+1,ribbon_cnt[i]);
    }
    

    return 0;
}