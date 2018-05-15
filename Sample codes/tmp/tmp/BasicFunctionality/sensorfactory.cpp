#include "sensorfactory.h"
#include <iostream>

void SensorFactory::notifyTopic(std::string topic)
{
    // Mutex that locks this class, for the scope of this function
    std::lock_guard<std::mutex> lock(classAccessMutex);
    LOG(INFO)<<"MQTT topic is: "<<topic;
    std::string type = getTypeFromTopic(topic), object = getObjectFromTopic(topic);
    LOG(DEBUG)<<"1) object = " << object << " | type = "<<type;
    if(!factory.count(object+type))
    {
        {
            LOG(DEBUG)<<"2) object = " << object << " type = "<<type;
            if(type == MQTTSettings::pedometer) factory[object+type] = std::make_shared<PedoMeter> ();            
            else if(type == MQTTSettings::windspeed) factory[object+type] = std::make_shared<WindSpeed> ();            
            else if(type == MQTTSettings::drivenDistane) factory[object+type] = std::make_shared<DrivenDistance> ();            
//            else if(type == MQTTSettings::correctionVector) factory[object+type] = std::make_shared<CorrectionVector> ();
            else if(type == MQTTSettings::absoluteWindDirection) factory[object+type] = std::make_shared<AbsoluteWindDirection> ();            
            else if(type == MQTTSettings::carCondensorVolatage) factory[object+type] = std::make_shared<CondensorVoltage>();
            else if(type == MQTTSettings::carPowerConsumed) factory[object+type] = std::make_shared<PowerConsumed>();
            else
            {
                LOG(WARN)<<"Some shit came in function SensorFactory::NotifyTopic function ...";
                return;
            }
        }
        factory[object+type]->pushSample(getSentValuefromTopic(topic));
        return;
    }
    if(factory.count(object+type))
    factory[object+type]->pushSample(getSentValuefromTopic(topic));
    LOG(INFO)<<"Number of sensor objects: " << sensors::getTotalAmountOfSensors();
}

void SensorFactory::deleteSensor(std::string mqttTopic)
{
	 std::lock_guard<std::mutex> lock(classAccessMutex);
    factory.erase(getTypeFromTopic(mqttTopic)+getObjectFromTopic(mqttTopic));
}

void SensorFactory::eraseFactoryContents(void)
{
	std::lock_guard<std::mutex> lock(classAccessMutex);
	std::map<std::string,std::shared_ptr<sensors>>::iterator it;
    for(it = factory.begin() ; it != factory.end(); ++it)
    {
        factory.erase(it);
    }
}

sensors& SensorFactory::getSensorObject(std::string requiredObject)
{
    std::lock_guard<std::mutex> lock(classAccessMutex);
    return *factory[requiredObject];
}

std::vector<std::string> SensorFactory::getSensorList()
{
    std::lock_guard<std::mutex> lock(classAccessMutex);
    std::vector<std::string> vReturn;
    for(std::map<std::string,std::shared_ptr<sensors>>::iterator it = factory.begin(); it != factory.end(); ++it)
    {
        vReturn.push_back(it->first);
    }
    return vReturn;
}

std::string SensorFactory::getObjectFromTopic(std::string topic)
{
    std::vector<std::string::iterator> slashbuf;
    for(std::string::iterator i = topic.begin();i < topic.end(); ++i)
    {
        if(*i == '/')slashbuf.push_back(i);
    }
    return std::string(slashbuf[0]+1,slashbuf[1]);
}
std::string SensorFactory::getSensorOrActuatorFromTopic(std::string topic)
{
    std::vector<std::string::iterator> slashbuf;
    for(std::string::iterator i = topic.begin();i < topic.end(); ++i)
    {
        if(*i == '/')slashbuf.push_back(i);
    }
    return std::string(slashbuf[1]+1,slashbuf[2]);
}
std::string SensorFactory::getTypeFromTopic(std::string topic)
{
    std::vector<std::string::iterator> slashbuf;
    for(std::string::iterator i = topic.begin();i < topic.end(); ++i)
    {
        if(*i == '/')slashbuf.push_back(i);
    }
    return std::string(slashbuf[2]+1,slashbuf[3]);
}

uint32_t SensorFactory::getSentValuefromTopic(std::string topic)
{
    std::vector<std::string::iterator> slashbuf;
    for(std::string::iterator i = topic.begin();i < topic.end(); ++i)
    {
        if(*i == '/')slashbuf.push_back(i);
    }

    return std::stoi(std::string(slashbuf[3]+1,topic.end()));
}

