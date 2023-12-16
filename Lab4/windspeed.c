/*******************************************************************
 * Student Name: Vicente Mba Engung
 * Student Number: 041029226
 * Course: 23F_CST8234
 * Declaration:
 * This is my own original work except where sources have been cited.
 *******************************************************************/

#include "windspeed.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Reads lines from the standard input (stdin).
 * Parse each line as a WindSpeedMessage, extracting a timestamp,
 * a type identifier, a speed in kmPerH, and a direction in degrees.
 */
int readWindSpeedMessage(WindSpeedMessage *windSpeed)
{
    char line[100];
    int type;
    while (fgets(line, sizeof(line), stdin) != NULL)
    {
        if (sscanf(line, "%ld,%d,%lf,%d", &windSpeed->timestamp, &type, &windSpeed->kmPerH, &windSpeed->degrees) == 4 && type == 2)
        {
            /**
             * Successfully read a WindSpeedMessage.
             */
            return 1;
        }
    }

    /**
     * Reset file position indicator to the beginning of stdin.
     */
    rewind(stdin);

    /**
     * Error reading line or reaching the end of file.
     */
    return 0;
}
