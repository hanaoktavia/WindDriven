#ifndef WINDSPEED_H
#define WINDSPEED_H

#include "sensors.h"


class WindSpeed : public sensors
{
public:
    WindSpeed();
    int getLastSampleKilometrePerHour(void) const;
    int getLastSampleMetrePerSecond(void) const;
    int getLastSampleBaufort(void)const ;
    int getLastSampleKnots(void) const;

};

#endif // WINDSPEED_H
