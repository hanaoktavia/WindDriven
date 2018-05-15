#ifndef TopicSimulator_H
#define TopicSimulator_H

#include <thread>
#include <atomic>
#include "sensorfactory.h"

class TopicSimulator
{
public:
    TopicSimulator(TopicReceiver &topicReceiver);
    void terminateSubscriber(void);
    ~TopicSimulator();

private:
    std::atomic<bool> stayTuned {true};
    TopicReceiver& objectToNotify;
    std::thread * readerThread;
    void readerThreadFunction(void);
    void informTopicReceiver(std::string topic);
};

#endif // TopicSimulator_H
