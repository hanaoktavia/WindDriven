#ifndef UARTTRANSLATOR_H
#define UARTTRANSLATOR_H

#include <string>
#include <thread>
#include <atomic>
#include "uartclass.h"
#include "topicreceiver.h"
#include "../settings.h"

class UartTranslator
{
public:
    UartTranslator(TopicReceiver &topicReceiver, UartClass & uartClass);
    ~UartTranslator();
    void start();
    bool stop();

private:

    std::thread * translatorThread;
    void translatorThreadFunction();
    std::atomic<bool> translatorThreadRunning{false};
    std::atomic<bool> translatorThreadDone{false};

    TopicReceiver * topicReceiver;
    UartClass * uartClass;

    std::string getObject(int i);
    std::string getSensor(int i);
    std::string getType(int i);
    std::string getValue(int MSB, int sMSB, int sLSB, int LSB, int decodingKey);
    int getDecodingKey(int i);
};

#endif // UARTTRANSLATOR_H
