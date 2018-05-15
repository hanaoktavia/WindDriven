#include "windspeed.h"

WindSpeed::WindSpeed()
{

}

int WindSpeed::getLastSampleBaufort(void) const
{
    return vSensorValue.back()*1.94384449244/5+1;
}

int WindSpeed::getLastSampleKilometrePerHour(void) const
{
    return vSensorValue.back()/3.6;
}

int WindSpeed::getLastSampleKnots(void) const
{
    return vSensorValue.back()*1.94384449244;
}

int WindSpeed::getLastSampleMetrePerSecond(void) const
{
    return vSensorValue.back();
}
