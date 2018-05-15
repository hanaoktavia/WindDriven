#ifndef UARTCLASS_H
#define UARTCLASS_H
#include "../log.h"
#include <unistd.h>			//Used for UART
#include <fcntl.h>			//Used for UART
#include <termios.h>		//Used for UART
#include <string>
#include <string.h>
#include <settings.h>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include <iostream>
#include <algorithm>

class UartClass
{
public:
    UartClass();
    ~UartClass();
    void sendString(std::string data);
    void sendArray(char tx_buffer[]);
//    void sendChar(char c);
    std::string  receiveString();
    void receiveArray(char (&array)[6]);
    //char* receiveArray();
//    std::string receiveArray();

//    char receiveChar();
private:
    void receiveThreadFunction();
    std::thread * receiveThread;
    bool running = false;

    int uart0_filestream = -1;
//    std::vector<char> rxBuffer;
    std::string rxBuffer;
    std::mutex tex;
};

#endif // UARTCLASS_H
