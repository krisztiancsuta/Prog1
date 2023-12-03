//[3 4 1 -3 -2 5 2] & [-3 8 4 5 6]  -- [4 -3 5]
#include<stdlib.h>
#include<stdio.h>
int isin(int *t, int meret, int a)
{
    for (int i = 0; i < meret; i++)
    {
        if (a == t[i])
            return 1; // benne van
    }
    return 0; // nincs benne
}

int *intersection(int t1[], int size1, int t2[], int size2, int *n)
{

    int min_length = size1 < size2 ? size1 : size2;
    int max_length = size1 > size2 ? size1 : size2; 

    int *p = size1 < size2 ? t1:t2; // mit nezzunk
    int *p2 =  size1 > size2 ? t1:t2; // honnan
    if(size1 == size2)
    {
        p = t1;
        p2 = t2;
    }
    int cnt = 0;
    for(int i = 0; i < min_length; i++){
        if(isin(p2,max_length,p[i]))
            cnt++;
    }
    int *res = (int*) malloc(cnt*sizeof(int));
    *n = cnt;
    cnt = 0;
    for(int i = 0; i < min_length; i++){
        if(isin(p2,max_length,p[i])){
            res[cnt] = p[i];
            cnt++;
        }
    }

    return res;
}

int main(){
    int t[1] = {3};
    int t2[3] = {1,2,3};
    int n;
    int *p = intersection(t, 1, t2,3, &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }

    free(p);

    return 0;
}