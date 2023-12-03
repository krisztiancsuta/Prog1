
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "debugmalloc.h"

typedef struct
{
    unsigned length;       // bytok szama
    unsigned char *number; // tomb kezdo cime
} big_number_t;

unsigned char hexa_value(char a)
{
    if (a >= '0' && a <= '9')
    {
        return a - '0';
    }
    if (a >= 'a' && a <= 'z')
        a = a - ' ';
    if (a >= 'A' && a <= 'F')
    {
        return 10 + a - 'A';
    }
    return -1;
}

// "102\0"
// 0 1 0 2
// 4 bit 4 bit 4 bit 4bit
big_number_t create(char *s)
{
    int res = 0;
    int length = strlen(s);
    int temp = 0;
    big_number_t num;
   
    int size;
    if (length % 2 == 0)
        size = length / 2;
    else
        size = length / 2 + 1;
    num.number = (unsigned char *)malloc(size);
    if (num.number == NULL)
    {
        exit(1); // Memória foglalási hiba esetén NULL-t adunk vissza
    }

    int j = 0;
    int cnt = 1;
    num.length = size;
    for (int i = length - 1; i >= 0; i--)
    {
        if (cnt % 2 != 0)
        {
            temp = hexa_value(s[i]);
            num.number[j] = temp;
            //2
        }
        if (cnt % 2 == 0)
        {
            num.number[j] += hexa_value(s[i]) * 16;
            j++;
        }
        cnt++;
        // forditva beirja az elemeket a tombbe
    }
    // 2 + 0 * 16 , 1
    return num;
}
// visszater egy stringgel
char *tostring(big_number_t a)
{
    //256 -> 0100;
    char *str = (char *)malloc(a.length * 2 + 1);// '\0'

    char *p = str;
    for (int i = a.length - 1; i >= 0; i--)
    {
        sprintf(p, "%02X", a.number[i]);
        p += 2;
    }
    *p = '\0';
    return str;
}

void destroy(big_number_t *a)
{
    a->length = 0;
    free(a->number);
    a->number = NULL;
}

big_number_t add(big_number_t a, big_number_t b)
{
    int max_length = a.length > b.length ? a.length : b.length;
    int min_length = a.length < b.length ? a.length : b.length;
    int maradek = 0;
    big_number_t res;
    for (int i = 0; i < max_length; i++)
    {
        unsigned char a_byte = (i < a.length) ? a.number[i] : 0;
        unsigned char b_byte = (i < b.length) ? b.number[i] : 0;
        if (a_byte + b_byte + maradek < 256)
        {
            maradek = 0;
        }
        else
        {
            //maradek = a_byte + b_byte + maradek - 256;
            maradek =(a_byte + b_byte)/256;
        }
    }

    if (maradek != 0)
    {
        res.length = max_length + 1;
    }
    else
        res.length = max_length;

    res.number = (unsigned char *)malloc(res.length);

    if (res.number == NULL)
    {
        exit(1); // Memória foglalási hiba esetén NULL-t adunk vissza
    }

    maradek = 0;
    int ertek = 0;
    for (int i = 0; i < res.length; i++)
    {

        unsigned char a_byte = (i < a.length) ? a.number[i] : 0;
        unsigned char b_byte = (i < b.length) ? b.number[i] : 0;

        if (a_byte + b_byte + maradek < 256)
        {
            res.number[i] = a_byte + b_byte + maradek;
            maradek = 0;
        }
        else
        {
            ertek = (a_byte + b_byte + maradek) - 256;
            
            res.number[i] = ertek;
            
            maradek = (a_byte + b_byte)/256; 
            
        }
    }
    return res;
}

int main()
{
   // 0x98;0x7B;0x9B;0xF7;0xFF;0x2C;0x19;0xE1;0x85;0x2E;0x93;0x74;0x5C;0xBE;0x1C;0x2E;0xB0;0xAB;0x6D;0x3B;0x28;0x89;0x7D;0x76;
    //0x20;0x52;0x27;0x6C;0x46;0x9C;0xE9;0x28;0xF6;0xF6;0xD4;0x58;0x3C;0x34;0xBF;0x0B;0x19;0x0D;0x6C;0x74;0x98;0x7B;0xF7;0x9B;0x2E;0x1C;0xE1;0x85;0x2E;0x93;0x74;0x5C;0xBE;0x1C;0x2E;0xB0;0xAB;0x6D;0x3B;0x28;0x89;0x7D;0x76;
    // 767D89283B6DBAB02E1CBE5C7493A2E185E1E192CFF79B7B98 +
    // 746C0D190BBFC34B43CD58D4F6F628E9C46C275220
    // 0FB928A70ACE83DD7199CD728BDFA4DB39451FC198F1BCF2E8 +
    // CA53CDE9C8DA3038547250A526118F949E76B5F7ED
    //
    big_number_t a = create("767D89283B6DBAB02E1CBE5C7493A2E185E1E192CFF79B7B98");
    big_number_t b = create("746C0D190BBFC34B43CD58D4F6F628E9C46C275220");
    big_number_t c = add(a, b);
    char *str = tostring(c);
    for (int i = 0; i < a.length; i++)
    {
        printf("%3d ", a.number[i]);
    }
    printf("\n");
    for (int i = 0; i < b.length; i++)
    {
        printf("%3d ", b.number[i]);
    }
    printf("\n");
    for (int i = 0; i < c.length; i++)
    {
        printf("%d ", c.number[i]);
    }

    printf("\n%s ", str);

    destroy(&a);
    destroy(&b);
    destroy(&c);
    free(str);
    return 0;
}