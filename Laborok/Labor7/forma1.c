#include <stdio.h>
typedef struct versenyhetvege
{
    int pole_position;
    double best_lap;

} versenyhetvege;

typedef struct pilot
{
    int racing_number;
    char name[4];
    versenyhetvege qualifying_results[3];

} pilot;

int main()
{
    pilot t[2] = {
        {1,{'M','S','C'}, {{1, 67.423}, {3, 46.735}, {1, 70.264}}},
        {2, {'M','A','S'}, {{2, 67.433}, {5, 46.855}, {3, 70.317}}} };

    printf("%d %s \n%d %.2f \n%d %.2f \n%d %.2f\n", t[0].racing_number, t[0].name,
           t[0].qualifying_results[0].pole_position,
           t[0].qualifying_results[0].best_lap,
           t[0].qualifying_results[1].pole_position,
           t[0].qualifying_results[1].best_lap,
           t[0].qualifying_results[2].pole_position,
           t[0].qualifying_results[2].best_lap);
           
    printf("%d %s \n%d %.2f \n%d %.2f \n%d %.2f\n", t[1].racing_number, t[1].name,
           t[1].qualifying_results[0].pole_position,
           t[1].qualifying_results[0].best_lap,
           t[1].qualifying_results[1].pole_position,
           t[1].qualifying_results[1].best_lap,
           t[1].qualifying_results[2].pole_position,
           t[1].qualifying_results[2].best_lap);

    return 0;
}