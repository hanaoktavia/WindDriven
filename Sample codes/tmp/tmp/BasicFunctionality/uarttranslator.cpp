#include "uarttranslator.h"



UartTranslator::UartTranslator(TopicReceiver &topicReceiver, UartClass &uartClass): uartClass(&uartClass), topicReceiver(&topicReceiver)
{

}

UartTranslator::~UartTranslator()
{
    translatorThreadRunning = false;
    translatorThread->join();
}

void UartTranslator::start()
{
    translatorThreadRunning = true;
    translatorThreadDone = false;
    translatorThread = new std::thread(&UartTranslator::translatorThreadFunction, this);
}

bool UartTranslator::stop()
{
    translatorThreadRunning = false;
    while(!translatorThreadDone){;}
    return true;
}

void UartTranslator::translatorThreadFunction()
{
    while(translatorThreadRunning)
    {
        char received[6];
        uartClass->receiveArray(received);
        //char received = uartClass->receiveArray();
        LOG(DEBUG)<<"In translatorThread: " <<std::hex
                                            <<received[0]<<" "
                                            <<received[1]<<" "
                                            <<received[2]<<" "
                                            <<received[3]<<" "
                                            <<received[4]<<" "
                                            <<received[5]<<" ";
        std::cout<<std::dec;
        if(received[0] != '\0')
        {
            topicReceiver->notifyTopic("/"+getObject(received[0])+"/"+getType(serial::SENSOR)+"/"+getSensor(received[1])+"/"+getValue(received[2],received[3],received[4],received[5],serial::NODE1));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

//        std::string received = uartClass->receiveArray();

//        if(received.at(0) != '\0')
//        {
//            topicReceiver->notifyTopic("/"+getObject(received.at(0))+"/"+getType(serial::SENSOR)+"/"+getSensor(received.at(1))+"/"+getValue(received.at(2),received.at(3),received.at(4),received.at(5),getDecodingKey(received.at(0))));
//        }
//        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    translatorThreadDone = true;
    LOG(WARN)<<"UartTranslator thread terminated";
}

std::string UartTranslator::getObject(int i)
{
    switch (i) {
    case serial::CAR:
    case serial::NODE5:
        return "car ";
        break;
    case serial::NODE1:
        return "node 1 ";
        break;
    case serial::NODE2:
        return "node 2 ";
        break;
    case serial::NODE3:
        return "node 3 ";
        break;
    case serial::NODE4:
        return "node 4 ";
        break;
//    case serial::NODE5:
//        return "node 5 ";
//        break;
    case serial::NODE6:
        return "node 6 ";
        break;
    case serial::NODE7:
        return "node 7 ";
        break;
    case serial::NODE8:
        return "node 8 ";
        break;
    default:
        return " ##unknown object## ";
        break;
    }
}

std::string UartTranslator::getType(int i){
    switch (i) {
    case serial::SENSOR:
        return "sensor";
        break;
    case serial::ACTOR:
        return "actor";
        break;
    default:
        return " ##unknown type## ";
        break;
    }
}

std::string UartTranslator::getValue(int MSB, int sMSB, int sLSB, int LSB, int decodingKey)
{
    uint32_t encrypted = MSB << 24 | sMSB << 16 | sLSB << 8 | LSB;
    return std::to_string((4294967295-encrypted)/decodingKey);
}

int UartTranslator::getDecodingKey(int i)
{
    switch (i) {
    case serial::CAR:
        return serial::CAR_KEY;
        break;
    case serial::NODE1:
        return serial::NODE1_KEY;
        break;
    case serial::NODE2:
        return serial::NODE2_KEY;
        break;
    case serial::NODE3:
        return serial::NODE3_KEY;
        break;
    case serial::NODE4:
        return serial::NODE4_KEY;
        break;
    case serial::NODE5:
        return serial::NODE5_KEY;
        break;
    case serial::NODE6:
        return serial::NODE6_KEY;
        break;
    case serial::NODE7:
        return serial::NODE7_KEY;
        break;
    case serial::NODE8:
        return serial::NODE8_KEY;
        break;
    default:
        return 0xFF;
        break;
    }
}

std::string UartTranslator::getSensor(int i)
{
    LOG(DEBUG) << "Sensor value in translator is: "<<i;
    switch (i) {
    case serial::windspeed:
        return MQTTSettings::windspeed;
        break;
    case serial::absoluteWindDirection:
        return MQTTSettings::absoluteWindDirection;
        break;
    case serial::pedometer:
        return MQTTSettings::pedometer;
        break;
    case serial::carDirection:
        return MQTTSettings::carDirection;
        break;
//    case serial::correctionVector:
//        return MQTTSettings::correctionVector;
//        break;
//    case serial::carPowerGenerated:
//        return MQTTSettings::carPowerGenerated;
//        break;
    case serial::carPowerConsumed:
        return MQTTSettings::carPowerConsumed;
        break;
    case serial::carCondensorVolatage:
        return MQTTSettings::carCondensorVolatage;
        break;
    default:
        return "##unknown sensor##";
        break;
    }
}
