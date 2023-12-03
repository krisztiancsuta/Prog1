#include<stdio.h>
typedef struct time
{
    int hour;
    int min;
    int sec;

} time;

//  H eleme [0,23]
int time2sec(time t)
{
    // 00:00:00 ota eltelt secs
    return t.hour * 3600 + t.min * 60 + t.sec;
}
time sec2time(int secs)
{
    while (secs < 0)
    {
       secs = secs + 86400;
    }
    time t = {(secs / 3600) % 24,
              ((secs - t.hour * 3600) / 60) % 60,
              (secs - t.hour * 3600 - t.min * 60) % 60};
    // ejfeltol eltelt masodpercek szama
    // max 86400
    return t;
}

time timeplus(time t1, time t2){
    return sec2time(time2sec(t1) + time2sec(t2));
}

int timecmp(time t1, time t2){
    if(time2sec(t1) > time2sec(t2))
        return 1;
    if(time2sec(t1) < time2sec(t2))
        return -1;
    return 0;

}
void timereset(time *p){
    (*p).hour = 0;
    (*p).min = 0;
    (*p).sec = 0;
}

int main(void)
{
    time t1 = {2, 5, 0};
    int d = time2sec(t1);          // 7500
    time t2 = sec2time(474211490); // 1:40:02
    time t3 = sec2time(-2*86401);    // 23:50:00
    time workout_begins = {23, 15, 0};
    time workout_duration = {1, 40, 0};
    time workout_ends = timeplus(workout_begins, workout_duration);
    if (timecmp(workout_ends, workout_begins) < 0)
        printf("Hamarabb van vege, mint mikor kezdodik\n");
    time workout_begins2 = {23, 15, 0};
    timereset(&workout_begins2);
   
    return 0;
}