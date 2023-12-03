
#include<string.h>
int first_unique(char str[]){
    int szotar[256] = {0};
    int i;
    for ( i = 0; str[i] !='\0'; i++)
    {
        szotar[(int)str[i]]++;
    }

     for (i = 0; str[i] != '\0'; i++) {
        if (szotar[(int)str[i]] == 1) {
            return i;
        }
    }
    return -1;
}

int main(){
    int x = first_unique("alma");

    return 0;
}