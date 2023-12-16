/*******************************************************************
 * Student Name: Vicente Mba Engung
 * Student Number: 041029226
 * Course: 23F_CST8234
 * Declaration:
 * This is my own original work except where sources have been cited.
 *******************************************************************/

#include "temp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Reads lines from the standard input (stdin).
 * Parse each line as a TempMessage, extracting a timestamp,
 * a type identifier, and a temperature in Celsius.
 */
int readTempMessage(TempMessage *temp)
{
    char line[100];
    int type;
    while (fgets(line, sizeof(line), stdin) != NULL)
    {
        if (sscanf(line, "%ld,%d,%lf", &temp->timestamp, &type, &temp->celsius) == 3 && type == 1)
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
