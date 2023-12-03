#include<math.h>

typedef struct point
{
    double x;
    double y;
} point;

typedef struct time
{
    int hour;
    int minute;
    int second;
}time;

typedef struct record
{
    point position;
    time interval;

}record;

int in_seconds(time t)
{
    return t.hour * 3600 + t.minute * 60 + t.second;
}

double distance(point p1, point p2){
    return sqrt((pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2)));
}

double average_speed(record x[],int meret){
    double time = 0;
    double dist = 0;
    for(int i = 0; i < meret-1;i++){
        time = time + in_seconds(x[i+1].interval);
        dist = dist + distance(x[i].position,x[i+1].position);
    }
    return dist/time;
}

int main(){

record t[2] = {{{0, 0}, {0, 0, 0}}, {{1, 0}, {0, 0, 1}}};
double x = average_speed(t, 2);
return 0;
}