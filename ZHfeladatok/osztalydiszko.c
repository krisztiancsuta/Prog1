#include<stdio.h>
typedef enum sex
{
    BOY,
    GIRL
} sex;

typedef struct student
{
    sex sex;
    int height;
} student;

int partner(student s1, student s2)
{
    if (s1.sex == s2.sex || s1.height - s2.height >= 10 || s2.height - s1.height >= 10)
        return 0;
    return 1;
}

int num_partners(student t[], int meret, int idx)
{
    int cnt = 0;
    for (int i = 0; i < meret; i++)
    {
        if (partner(t[i], t[idx]))
            cnt++;
    }
    return cnt;
}

void tallest_and_partners(student osztaly[], int meret, int *idx, int *cnt)
{
    int i;
    int maxidx = 0;
    for (i = 1; i < meret; i++)
    {
        if (osztaly[maxidx].height < osztaly[i].height)
            maxidx = i;
    }
    *idx = maxidx;
    *cnt = num_partners(osztaly,meret,maxidx);
}

int main(){
    int cnt;
    int maxidx;
    student osztaly[3]={{BOY,180},{GIRL, 175},{GIRL,160}};
    tallest_and_partners(osztaly,3,&maxidx,&cnt);

    printf("%d %d",maxidx, cnt);

    return 0;
}
