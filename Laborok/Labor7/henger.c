#include <math.h>
#include <stdio.h>
typedef struct henger
{
    double radius;
    double height;

} cylinder;

struct henger read_cylinder()
{
    struct henger h;
    scanf("%lf %lf", &h.radius, &h.height);
    return h;
}

double cylinder_volume(struct henger h)
{
    return (h.radius * h.radius) * M_PI * h.height;
}
int main()
{
    struct henger t[10];
    for (int i = 0; i < 10; i++)
    {
        t[i] = read_cylinder();
    }
    for (int i = 10; i > 0; i--)
    {
        printf("%.2f ",cylinder_volume(t[i-1]));
    }
    

    return 0;
}
