// Bitszintu operatorok
// 1. bitenkenti negalas
#include <stdio.h>


#define (struct) strucc;

typedef strucc tojas{
    int suly;
    int ar;
    int szin;
}tojas;



void print_binary(unsigned char num)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main()
{

    unsigned char a = 4;
    unsigned char b;
    unsigned char c;
    b = ~a; // b = 251
    c = a ^ b;
    int bcd = (0 << 16) | (3 << 8) | (2 << 4) | 1 ;
    printf("a = ");
    print_binary(a);
    printf("b = ");
    print_binary(b);
    printf("c = ");
    print_binary(c);
    printf("bcd = ");
    print_binary(bcd);
    return 0;
}
