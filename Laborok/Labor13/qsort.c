#include<stdlib.h>
#include<stdio.h>
#include<math.h>

typedef struct {
    double x, y;
} point;

int dist(const void *_a, const void *_b){
    point *a = (point *)_a;
    point *b = (point *)_b;
    if(sqrt(pow(a->x, 2) + pow(a->y,2)) > sqrt(pow(b->x, 2) + pow(b->y,2))) return 1;
    if(sqrt(pow(a->x, 2) + pow(a->y,2)) < sqrt(pow(b->x, 2) + pow(b->y,2))) return -1;
    return 0;
}


void sort_points(point *t, int size){
    qsort(t,size,sizeof(point),dist);
}