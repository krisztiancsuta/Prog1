
#include<stdio.h>
int isprime(int a)
{
    int i;
    if (a < 2)
        return 0;
    for (i = 2; i * i <= a; i++)
        if (a % i == 0)
            return 0;
    return 1;
}
// Ikerprímek azok a prímek, melyek különbsége 2.
// a < b
// 1-10
int twin_primes(int a, int b)
{
    int p1, p2;
    int cnt = 0;
    for (int i = a; i <= b; i++)
    {
        if (isprime(i))
            p1 = i;
        else continue;
        for (int j = i + 1; j <= b; j++)
        {
            if (isprime(j)){
                p2 = j;
                if (p1 - p2 == 2 || p1 - p2 == -2)
                    cnt++;
            }else continue;
        }
    }
    return cnt;
}

int main(){
    int x = twin_primes(200,1000);
    printf("%d",x);
    return 0;
}