#include "absolutewinddirection.h"

#include <iostream>

AbsoluteWindDirection::AbsoluteWindDirection()
{

}

AbsoluteWindDirection::~AbsoluteWindDirection()
{
    std::cout<<"Last AbsoluteWindDirection value is: "<<getLastSample()<<std::endl;
}

int AbsoluteWindDirection::getLastSampleDegrees() const
{
    return vSensorValue.back();
}

int AbsoluteWindDirection::getLastSampleRadials() const
{
    return vSensorValue.back()*6.28/360;
}

int AbsoluteWindDirection::getAverageDegrees(unsigned short numberOfSamples) const
{
    int avg = 0;
    for(unsigned short i = 0; i <numberOfSamples-1 ; ++i)
    {
        avg+= vSensorValue.at(vSensorValue.back()-i);
    }
    return avg/numberOfSamples;
}

int AbsoluteWindDirection::getAverageRadials(unsigned short numberOfSamples) const
{
    int avg = 0;
    for(unsigned short i = 0; i <numberOfSamples-1 ; ++i)
    {
        avg+= vSensorValue.at(vSensorValue.back()-i);
    }
    return avg/numberOfSamples*6.28/360;
}
