#ifndef CORRECTIONVECTOR_H
#define CORRECTIONVECTOR_H

#include "sensors.h"

class CorrectionVector : public sensors
{
public:
    CorrectionVector();
    int getLastSampleDegrees() const;
    int getLastSampleRadials() const;
};

#endif // CORRECTIONVECTOR_H
