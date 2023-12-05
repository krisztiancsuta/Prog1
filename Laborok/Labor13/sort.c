


#include<math.h>


typedef  struct {
    double x,y;
}point;

void swap(point *a, point *b){
    point temp = *a;
    *a = *b;
    *b = temp;
}

int dist(point *a, point *b){
    if(sqrt(pow(a->x, 2) + pow(a->y,2)) > sqrt(pow(b->x, 2) + pow(b->y,2))) return 1;
    if(sqrt(pow(a->x, 2) + pow(a->y,2)) < sqrt(pow(b->x, 2) + pow(b->y,2))) return -1;
    return 0;
}

void sort_points(point *t, int size){

    for(int i = 0; i < size - 1;i++)
        for(int j = 0; j < size - i - 1; j++)
            if(dist(t + j, t + (j + 1)) > 0)
                swap(t + j, t + (j + 1));

}
