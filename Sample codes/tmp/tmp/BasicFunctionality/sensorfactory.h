#ifndef SENSORFACTORY_H
#define SENSORFACTORY_H

#include "topicreceiver.h"
#include "sensorcontainer.h"
#include <mutex>
#include <map>
#include <string>
#include <algorithm>
#include <stdint.h>
#include "sensors.h"
#include "absolutewinddirection.h"
#include "correctionvector.h"
#include "drivendistance.h"
#include "pedometer.h"
#include "windspeed.h"
#include "condensorvoltage.h"
#include "powerconsumed.h"
#include "../log.h"
#include "../settings.h"

class SensorFactory: public TopicReceiver, public SensorContainer
{
    public:
        static SensorFactory& theSensorFactory()
        {
            static SensorFactory theSensorFactory;
            return theSensorFactory;
        }
        void notifyTopic(std::string topic) override;
        void deleteSensor(std::string mqttTopic);
        void eraseFactoryContents(void);
        sensors& getSensorObject(std::string requiredObject) override;
        std::vector<std::string> getSensorList(void) override;

    private:
        SensorFactory() {}
        SensorFactory(SensorFactory const&) = delete;
        void operator=(SensorFactory const&) = delete;
        std::mutex classAccessMutex;

        std::string getObjectFromTopic(std::string);
        std::string getSensorOrActuatorFromTopic(std::string);
        std::string getTypeFromTopic(std::string);
        uint32_t getSentValuefromTopic(std::string);

        std::map<std::string,std::shared_ptr<sensors>> factory;
        bool isSlash(char in){return ('/' == in);}
};

#endif // SENSORFACTORY_H
