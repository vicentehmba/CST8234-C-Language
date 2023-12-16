/*******************************************************************
 * Student Name: Vicente Mba Engung
 * Student Number: 041029226
 * Course: 23F_CST8234
 * Declaration:
 * This is my own original work except where sources have been cited.
 *******************************************************************/

#include "windgusts.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Reads lines from the standard input (stdin).
 * Parse each line as a WindGustsMessage, extracting a timestamp,
 * a type identifier, a prev change, and a current change in the wind.
 */
int readWindGustsMessage(WindGustsMessage *windGusts)
{
    char line[100];
    int type;
    while (fgets(line, sizeof(line), stdin) != NULL)
    {
        if (sscanf(line, "%ld,%d,%lf,%lf", &windGusts->timestamp, &type, &windGusts->prev, &windGusts->current) == 4 && type == 3)
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
