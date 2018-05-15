#include "correctionvector.h"

CorrectionVector::CorrectionVector()
{

}

int CorrectionVector::getLastSampleDegrees() const
{
    return vSensorValue.back();
}

int CorrectionVector::getLastSampleRadials() const
{
    return vSensorValue.back()*6.28/360;
}
