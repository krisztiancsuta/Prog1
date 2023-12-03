#include<stdio.h>

int main(){
    int tomb[30] = {29,28,27,26,25,24,23,22,21,20,19,18
                    ,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    for (int i = 30; i > 1; i--)
    {
        for (int j = 0; j < i - 1 ; j++)
        {
            if(tomb[j]>tomb[j+1]){
               
                int x = tomb[j + 1];
                int y = tomb[j];
                tomb[j + 1] = y;
                tomb[j] = x;
            }
        }
        printf("%d \n",tomb[i-1]);
    }
    return 0;
}