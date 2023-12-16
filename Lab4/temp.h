#ifndef TEMP_H
#define TEMP_H

#include <time.h>

typedef struct
{
    time_t timestamp;
    int type;
    double celsius;
} TempMessage;

int readTempMessage(TempMessage *temp);

#endif
