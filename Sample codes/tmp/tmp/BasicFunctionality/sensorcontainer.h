#ifndef SENSORCONTAINER_H
#define SENSORCONTAINER_H

#include <memory>
#include <string>
#include <vector>

#include "sensors.h"


class SensorContainer
{
public:
//    virtual std::shared_ptr<sensors> getSensorObject(std::string requiredObject) = 0;
    virtual sensors& getSensorObject(std::string requiredObject) = 0;
    virtual std::vector<std::string> getSensorList(void) = 0;

};


#endif // SENSORCONTAINER_H
