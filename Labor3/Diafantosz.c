/*
Adott a következő diofantoszi egyenlet:

a x + b y = c
Diofantoszi egyenleteknek azokat az egyenleteket nevezzük, 
amelyeknek minden együtthatója és megoldása egész szám. 
Esetünket korlátozzuk a csak pozitív számokra. Írj standard C programot,
amely beolvassa a pozitív a b c együtthatókat, majd kiírja az összes x y megoldáspárt. 
A különböző megoldásokat x értéke szerint növekvő sorrenben külön sorba írja, az x és y számokat egy szóköz válassza el.

Amennyiben a bemenet pl. 2 8 26, akkor a kimenet legyen

1 3
5 2
9 1
*/
#include <stdio.h>

int main() {
    long long int a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);

    for (int x = 1; x <= c; x++) {
        for (int y = 1; y <= c; y++) {
            if (a * x + b * y == c) {
                printf("%d %d\n", x, y);
            }
            if (a * x + b * y > c) {
                break; 
            }
        }
    }

    return 0;
}