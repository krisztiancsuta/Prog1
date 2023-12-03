
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertTemperature(char *fahrenheit, char *celsius) {
    int fTemp = atoi(fahrenheit);
    double cTemp = (fTemp - 32) * 5.0 / 9.0;
    sprintf(celsius, "%.1fC", cTemp);
}

void convertDate(char *date, char *time, char *outputDate) {
    int month, day, year, hours, minutes, seconds;
    sscanf(date, "%d/%d/%d", &day, &month, &year);
    sscanf(time, "%d:%d:%d", &hours, &minutes, &seconds);
    sprintf(outputDate, "%04d.%02d.%02d %02d.%02d.%02d", year, month, day, hours, minutes, seconds);
}

int main() {
    char inputFileName[21], outputFileName[21];
    scanf("%20s %20s", inputFileName, outputFileName);

    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Error opening files");
        return 1;
    }

    char line[100], key[20], date[11], time[9], tempF[6], convertedTemp[10], convertedDate[25];
    
    while (fgets(line, sizeof(line), inputFile)) {
        sscanf(line, "%s %s %s", key, date, time);

        if (strcmp(key, "MEASUREMENT_TIME") == 0) {
            convertDate(date, time, convertedDate);
            fprintf(outputFile, "MERESI_IDO %s\n", convertedDate);
        } else if (strcmp(key, "TEMPERATURE") == 0) {
            sscanf(line, "%s %s", key, tempF); // Read the temperature
            convertTemperature(tempF, convertedTemp);
            fprintf(outputFile, "HOMERSEKLET %s\n", convertedTemp);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
