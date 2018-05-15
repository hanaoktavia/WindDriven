#ifndef PEDOMETER_H
#define PEDOMETER_H

#include "sensors.h"

class PedoMeter : public sensors
{
public:
    PedoMeter();
    ~PedoMeter();
    inline int getLastSampleKilometrePerHour(void) const;
    inline int getLastSampleMetrePerSecond(void) const;
    int getAverageSpeedMetrePerSecond(unsigned short numberOfSamples) const;
    int getAverageSpeedKilometrePerHour(unsigned short numberOfSamples) const;
};

#endif // PEDOMETER_H
