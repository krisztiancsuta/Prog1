/*
2 tonna teherbirasu a teherauto 
x kilot szakit le a gep 
ha tul lepne a 2 tonnat akkor nem rakja bele a leszakitott 
darabot

addig olvasok amig tudok 
0.2 1 0.7 0.3 0.6 0.3 1.1 0.3
0.2+1+0.7 -- 0.1t 
0.3+0.6+0.3 -- 0.8t
1.1 + 0.3 --- 0.6t
*/
#include<stdio.h>
int main(){
    int i = 0;
    double max = 2.0;
    double x;
    double sum = 0;
    double maradekok[1000] = {0};
    while(scanf("%lf",&x) == 1){
        sum = sum + x;
        if(sum > max){
            maradekok[i] = max-(sum - x);
            i++;
            sum = x;
        }
    }
    maradekok[i] = max - sum;
    i = 0;
    while(maradekok[i]!= 0.0){
        printf("%.3f ",maradekok[i]);
        i++;
    }

    return 0;
}
