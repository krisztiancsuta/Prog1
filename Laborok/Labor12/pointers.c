#include<stdio.h>
#include<stdlib.h>

int main(){
    int a = 5;
    int *p[5];
    for (int i = 0; i < 5; i++) {
        p[i] = (int *)malloc(sizeof(int));
        *p[i] = i;
        if (p[i] == NULL) {
            printf("Hiba a memória lefoglalásakor!");
            return 1;
        }
    }
    printf("a = %d\n", a);
    printf("a cime= %p\n", &a);

    for(int i = 0; i < 5; i++){
        printf("p[%d] = %d\n", i, *p[i]);
    }


    return 0;
}