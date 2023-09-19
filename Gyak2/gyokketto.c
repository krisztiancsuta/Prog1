#include<stdio.h>
#include<math.h>
//0 2 intervallumon nezem a es b szamtani kozepet 
// b bol kivonom a-t akkor annak az erteke kozeliti epsilont
int main(){
    int n;
    double a = 0, b = 2;
    double eps,res;;//nagyon pici szam 
    scanf("%lf %d",&eps, &n);
    while( b - a > eps)
    {
        res = (a + b)/2;
        if(pow(res,n) - 2 < 0)
        {
            a = res;
        }else{
            b = res;
        }

    }
    printf("%lf", res);



    return 0;
}