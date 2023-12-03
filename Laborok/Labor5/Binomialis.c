#include <stdio.h>
int lnko(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    int n;
    int k;
    int num[40];
    int szamlalo[40];
    scanf("%d%d", &n, &k);
    if (k > n - k)
        k = n - k;
    int meddigNum = n - k;
    int meddigSzam = k;
    for (int i = 0; i < k; i++)
    {
        num[i] = meddigNum + 1;
        szamlalo[i] = i + 1;
        meddigNum++;
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int oszto = lnko(num[i], szamlalo[j]);
            num[i] = num[i] / oszto;
            szamlalo[j] = szamlalo[j] / oszto;
        }
    }
    long long unsigned int szorzat = 1;
    for (int i = 0; i < k; i++)
    {
        szorzat = szorzat * num[i];
    }
    printf("%llu", szorzat);
    return 0;
}