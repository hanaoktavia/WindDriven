#include "sensors.h"

unsigned int sensors::uiTotalAmountOfSensors = 0;

sensors::sensors()
{
    //++sensors::uiTotalAmountOfSensors;
}

sensors::~sensors()
{
    //--sensors::uiTotalAmountOfSensors;
}

void sensors::pushSample(uint32_t sample)
{
    LOG(DEBUG)<<"In sensors::pushSample value is: "<<sample;
    vSensorValue.push_back(sample);
}

int sensors::getLastSample() const
{
    const int returnValue = vSensorValue.size() != 0 ? vSensorValue.back() : 0;
    LOG(DEBUG)<<"In sensors::getLastSample value is: "<<returnValue;
    return static_cast<int16_t>(returnValue);
}
