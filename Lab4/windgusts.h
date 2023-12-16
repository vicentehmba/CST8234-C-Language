#ifndef WINDGUSTS_H
#define WINDGUSTS_H

#include <time.h>

typedef struct
{
    time_t timestamp;
    int type;
    double prev;
    double current;
} WindGustsMessage;

int readWindGustsMessage(WindGustsMessage *windGusts);

#endif
