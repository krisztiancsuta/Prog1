#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *trim(char *str)
{

    int i = 0;
    for (i = 0; str[i] != '\0' && str[i] != '\n' && str[i] != '.'; i++)
        ;

    str[i] = '\0';
    return str;
}

void converttemp(char *fahrenheit, char *celsius) {
    
    double cTemp = (fTemp - 32) * 5.0 / 9.0;
    sprintf(celsius, "%.1fC", cTemp);
}


void convertdate(char *date, char *converted){
    int month, day, year;
    int hours, minutes, seconds;
    sscanf(date, "%d/%d/%d %d:%d:%d", &month, &day, &year, &hours, &minutes, &seconds);
    sprintf(converted, "%d.%02d.%02d %02d.%02d.%02d", year, month, day, hours, minutes, seconds);
}
int main()
{

    char fileName[21];
    char output[21];
    char line[102]; //\0,\n
    char translated[102];
    
    scanf("%20s %20s", fileName, output);
   

    FILE *p = fopen(fileName, "r");
    if (p == NULL)
        return 0;
   
    FILE *p2 = fopen(output, "w");

    char date[20], tempF[10], convertedTemp[10], convertedDate[25];
    while (fscanf(p, "%*s %s %*s %s", date, tempF)==2)
    {
        convertdate(date,convertedDate);
        converttemp(tempF, convertedTemp);
        fprintf(p2,"MERESI_IDO %s\nHOMERSEKLET %s\n", convertedDate, convertedTemp);
       
    }

    fclose(p2);
    fclose(p);
    return 0;
}