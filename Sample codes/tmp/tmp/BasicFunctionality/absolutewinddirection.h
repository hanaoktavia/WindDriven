#ifndef ABSOLUTEWINDDIRECTION_H
#define ABSOLUTEWINDDIRECTION_H

#include "sensors.h"

class AbsoluteWindDirection : public sensors
{
public:
    AbsoluteWindDirection();
    ~AbsoluteWindDirection();
    int getLastSampleDegrees() const;
    int getLastSampleRadials() const;
    int getAverageDegrees(unsigned short numberOfSamples) const;
    int getAverageRadials(unsigned short numberOfSamples) const;
};

#endif // ABSOLUTEWINDDIRECTION_H
