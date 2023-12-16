#ifndef WINDSPEED_H
#define WINDSPEED_H

#include <time.h>

typedef struct
{
    time_t timestamp;
    int type;
    double kmPerH;
    int degrees;
} WindSpeedMessage;

int readWindSpeedMessage(WindSpeedMessage *windSpeed);

#endif
