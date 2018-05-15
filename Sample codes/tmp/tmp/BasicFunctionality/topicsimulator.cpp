/* * Compile settings *************************** */
#define MQTTsimulated
/* ********************************************** */

#include "topicsimulator.h"

#ifdef MQTTsimulated
#include <iostream>
#include <fstream>
#endif

TopicSimulator::TopicSimulator(TopicReceiver &topicReceiver)
: objectToNotify(topicReceiver)
{

    readerThread = new std::thread(&TopicSimulator::readerThreadFunction,this);
}

void TopicSimulator::readerThreadFunction(void)
{
#ifdef MQTTsimulated
    // Read topics and messages out of a file
    std::ifstream topicFile("../GUI/topicsimulation.txt");
    while(stayTuned)
    {
        std::string theLine;
        if( std::getline(topicFile, theLine) )
        {
            informTopicReceiver(theLine);
        }
        else
        {
            terminateSubscriber();
        }

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

#else
    #error "Real MQTT was not implemented yet"
#endif
}

void TopicSimulator::terminateSubscriber(void)
{
#ifdef MQTTsimulated
    LOG(DEBUG) << "Terminated the MQTT simulator thread.";
#endif
    stayTuned = false;
}

void TopicSimulator::informTopicReceiver(std::string topic)
{
    objectToNotify.notifyTopic(topic);
}


TopicSimulator::~TopicSimulator()
{
    terminateSubscriber();
    readerThread->join();
    delete readerThread;
}
