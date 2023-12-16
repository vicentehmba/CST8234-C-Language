/*******************************************************************
 * Student Name: Vicente Mba Engung
 * Student Number: 041029226
 * Course: 23F_CST8234
 * Declaration:
 * This is my own original work except where sources have been cited.
 *******************************************************************/

#include "temp.h"
#include "windspeed.h"
#include "windgusts.h"
#include <stdio.h>

#define ARRAY_SIZE 100

/**
 * convert the time stamp to the format: yyyy/mm/dd hh:mm:ss
 */
void printFormattedTime(const time_t timestamp)
{
    const struct tm *timeInfo = localtime(&timestamp);

    if (timeInfo != NULL)
    {
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y/%m/%d %H:%M:%S", timeInfo);
        printf("%s", buffer);
    }
    else
    {
        printf("Invalid timestamp");
    }
}

/**
 * Read and process Temp messages.
 */
void processTempMessages(void)
{
    int i;

    TempMessage tempArray[ARRAY_SIZE];
    int tempCount = 0;
    while (tempCount < ARRAY_SIZE && readTempMessage(&tempArray[tempCount]))
    {
        tempCount++;
    }

    /**
     * Print Temp messages.
     */
    printf("Date\t   Time\t    Celsius\n");
    for (i = 0; i < tempCount; ++i)
    {
        printFormattedTime(tempArray[i].timestamp);
        printf(" %.2lf\n", tempArray[i].celsius);
    }
}

/**
 * Read and process WindSpeed messages.
 */
void processWindSpeedMessages(void)
{
    int i;

    WindSpeedMessage windSpeedArray[ARRAY_SIZE];
    int windSpeedCount = 0;
    while (windSpeedCount < ARRAY_SIZE && readWindSpeedMessage(&windSpeedArray[windSpeedCount]))
    {
        windSpeedCount++;
    }

    /**
     * Print windspeed messages.
     */
    printf("\nDate\t   Time\t    Speed Direction\n");
    for (i = 0; i < windSpeedCount; ++i)
    {
        printFormattedTime(windSpeedArray[i].timestamp);
        printf(" %.2lf %d\n", windSpeedArray[i].kmPerH, windSpeedArray[i].degrees);
    }
}

/**
 * Read and process WindGusts messages.
 */
void processWindGustsMessages(void)
{
    int i;

    WindGustsMessage windGustsArray[ARRAY_SIZE];
    int windGustsCount = 0;
    while (windGustsCount < ARRAY_SIZE && readWindGustsMessage(&windGustsArray[windGustsCount]))
    {
        windGustsCount++;
    }

    /**
     * Print windgust messages.
     */
    printf("\nDate\t   Time\t    Wind Change\n");
    for (i = 0; i < windGustsCount; ++i)
    {
        printFormattedTime(windGustsArray[i].timestamp);
        printf(" ");

        /**
         * Determine wind changes.
         */
        if (windGustsArray[i].current > windGustsArray[i].prev)
        {
            printf("Increasing\n");
        }
        else if (windGustsArray[i].current < windGustsArray[i].prev)
        {
            printf("Decreasing\n");
        }
        else
        {
            printf("Unchanged\n");
        }
    }
}

int main(void)
{
    processTempMessages();
    processWindSpeedMessages();
    processWindGustsMessages();

    return 0;
}
