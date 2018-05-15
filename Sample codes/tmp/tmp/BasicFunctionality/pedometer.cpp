#include "pedometer.h"
#include <iostream>

PedoMeter::PedoMeter()
{

}

PedoMeter::~PedoMeter()
{
    std::cout<<"Last PedoMeter value is: "<<getLastSample()<<std::endl;
}

int PedoMeter::getLastSampleKilometrePerHour(void) const
{
    return vSensorValue.back()/3.6;
}

int PedoMeter::getLastSampleMetrePerSecond(void) const
{
    return vSensorValue.back();
}

int PedoMeter::getAverageSpeedMetrePerSecond(unsigned short numberOfSamples) const
{
    int avg = 0;
    for(unsigned short i = 0; i <numberOfSamples-1 ; ++i)
    {
        avg+= vSensorValue.at(vSensorValue.back()-i);
    }
    return avg/numberOfSamples;
}

int PedoMeter::getAverageSpeedKilometrePerHour(unsigned short numberOfSamples) const
{
    int avg = 0;
    for(unsigned short i = 0; i <numberOfSamples-1 ; ++i)
    {
        avg+= vSensorValue.at(vSensorValue.back()-i);
    }
    return avg/numberOfSamples/3.6;
}
