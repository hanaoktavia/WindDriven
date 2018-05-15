#ifndef SENSORS_H
#define SENSORS_H
#include <string>
#include <vector>
#include <iostream>
#include "../log.h"

class sensors
{
public:
    sensors();
    ~sensors();
    inline std::string getName(void)const{return sSensorName;}
    inline void setName(std::string newName){sSensorName = newName;}
    static unsigned int getTotalAmountOfSensors(){return 1;/*uiTotalAmountOfSensors;*/}
    int getLastSample(void)const;
    void pushSample(uint32_t sample);

protected:
    std::string sSensorName;
    std::vector<uint32_t> vSensorValue;
private:
    static unsigned int uiTotalAmountOfSensors;
};
#endif // SENSORS_H
