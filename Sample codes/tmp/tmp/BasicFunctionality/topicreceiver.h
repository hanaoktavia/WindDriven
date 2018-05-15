#ifndef TOPICRECEIVER_H
#define TOPICRECEIVER_H

#include <string>

class TopicReceiver
{
public:
    virtual void notifyTopic(std::string topic) = 0;
};

#endif // TOPICRECEIVER_H
