#include "uartclass.h"

UartClass::UartClass()
{
    //-------------------------
    //----- SETUP USART 0 -----
    //-------------------------
    //At bootup, pins 8 and 10 are already set to UART0_TXD, UART0_RXD (ie the alt0 function) respectively


    //OPEN THE UART
    //The flags (defined in fcntl.h):
    //	Access modes (use 1 of these):
    //		O_RDONLY - Open for reading only.
    //		O_RDWR - Open for reading and writing.
    //		O_WRONLY - Open for writing only.
    //
    //	O_NDELAY / O_NONBLOCK (same function) - Enables nonblocking mode. When set read requests on the file can return immediately with a failure status
    //											if there is no input immediately available (instead of blocking). Likewise, write requests can also return
    //											immediately with a failure status if the output can't be written immediately.
    //
    //	O_NOCTTY - When set and path identifies a terminal device, open() shall not cause the terminal device to become the controlling terminal for the process.
    uart0_filestream = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY);		//Open in non blocking read/write mode
    if (uart0_filestream == -1)
    {
        //ERROR - CAN'T OPEN SERIAL PORT
        LOG(ERROR)<<"Error - Unable to open UART.";
    }

    //CONFIGURE THE UART
    //The flags (defined in /usr/include/termios.h - see http://pubs.opengroup.org/onlinepubs/007908799/xsh/termios.h.html):
    //	Baud rate:- B1200, B2400, B4800, B9600, B19200, B38400, B57600, B115200, B230400, B460800, B500000, B576000, B921600, B1000000, B1152000, B1500000, B2000000, B2500000, B3000000, B3500000, B4000000
    //	CSIZE:- CS5, CS6, CS7, CS8
    //	CLOCAL - Ignore modem status lines
    //	CREAD - Enable receiver
    //	IGNPAR = Ignore characters with parity errors
    //	ICRNL - Map CR to NL on input (Use for ASCII comms where you want to auto correct end of line characters - don't use for bianry comms!)
    //	PARENB - Parity enable
    //	PARODD - Odd parity (else even)
    struct termios options;
    tcgetattr(uart0_filestream, &options);
    options.c_cflag = B115200 | CS8 | CLOCAL | CREAD;		//<Set baud rate
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcflush(uart0_filestream, TCIFLUSH);
    tcsetattr(uart0_filestream, TCSANOW, &options);

    running=true;
    receiveThread = new std::thread(&UartClass::receiveThreadFunction,this);
}

UartClass::~UartClass()
{
    running=false;
}

void UartClass::sendString(std::string data)
{

    //----- TX BYTES -----
    char tx_buffer[10];
    strncpy(tx_buffer,data.c_str(),sizeof(tx_buffer));

    if (uart0_filestream != -1)
    {
        int count = write(uart0_filestream, &tx_buffer[0], 6);		//Filestream, bytes to write, number of bytes to write
        if (count < 0)
        {
            LOG(ERROR)<<"UART TX ERROR!";
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
void UartClass::sendArray(char tx_buffer[6])
{
    if (uart0_filestream != -1)
    {
        int count = write(uart0_filestream, &tx_buffer[0], 6);		//Filestream, bytes to write, number of bytes to write
        if (count < 0)
        {
            LOG(ERROR)<<"UART TX ERROR!";
        }
    }
}

std::string UartClass::receiveString()
{
//----- CHECK FOR ANY RX BYTES -----
    if (uart0_filestream != -1)
    {
        // Read up to 255 characters from the port if they are there
        char rx_buffer[10];
        int rx_length = read(uart0_filestream, (void*)rx_buffer, 6);		//Filestream, buffer to store in, number of bytes to read (max)
        if (rx_length < 0)
        {
            //An error occured (will occur if there are no bytes)
            LOG(ERROR)<<"No bytes available in UART";
        }
        else if (rx_length == 0)
        {
            //No data waiting
            printf("No data in buffer");
        }
        else
        {
            //Bytes received
            rx_buffer[rx_length] = '\0';
            LOG(INFO) << rx_length << "bytes read : " << rx_buffer;
//            printf("%i bytes read : %s\n", rx_length, rx_buffer);
        }
        return rx_buffer;
    }
    return '\0';
}

void UartClass::receiveArray(char (&buf)[6])
{
    std::lock_guard<std::mutex> lock(tex);
    LOG(DEBUG)<<"Receive array rx buffer size: "<<rxBuffer.size();
    if(rxBuffer.size() >= 9)
    {
        auto it = std::find(rxBuffer.begin(),rxBuffer.end(),serialSequence::FIRST);
        if(it != rxBuffer.end())
        {
            if((*(it+1)==serialSequence::SECOND) and (*(it+2)==serialSequence::THIRD))
            {
                buf[0] = *(it+3);
                buf[1] = *(it+4);
                buf[2] = *(it+5);
                buf[3] = *(it+6);
                buf[4] = *(it+7);
                buf[5] = *(it+8);
                rxBuffer.erase(rxBuffer.begin(),it+9);
            }
        }
//        std::cout<<"rxBuffer = "<<std::hex<<(int)rxBuffer.at(0)<<" "<<(int)rxBuffer.at(1)<<" "<<(int)rxBuffer.at(2)<<" "<<(int)rxBuffer.at(3)<<" "<<(int)rxBuffer.at(4)<<" "<<(int)rxBuffer.at(5)<<std::endl;
//        std::cout<<std::dec;
//        buf[0] = rxBuffer[0];
//        buf[1] = rxBuffer[1];
//        buf[2] = rxBuffer[2];
//        buf[3] = rxBuffer[3];
//        buf[4] = rxBuffer[4];
//        buf[5] = rxBuffer[5];
//        rxBuffer.erase(rxBuffer.begin(),rxBuffer.begin()+6);

    }
    else
        buf[0] = '\0';
}

//char *UartClass::receiveArray()
//{
//    std::lock_guard<std::mutex> lock(tex);
//    if(rxBuffer.size() >= 6)
//    {
//        std::cout<<"rxBuffer = "<<std::hex<<(int)rxBuffer.at(0)<<(int)rxBuffer.at(1)<<(int)rxBuffer.at(2)<<(int)rxBuffer.at(3)<<(int)rxBuffer.at(4)<<(int)rxBuffer.at(5)<<std::endl;
//        char buf[6];
//        buf[0] = rxBuffer[0];
//        buf[1] = rxBuffer[1];
//        buf[2] = rxBuffer[2];
//        buf[3] = rxBuffer[3];
//        buf[4] = rxBuffer[4];
//        buf[5] = rxBuffer[5];
//        rxBuffer.erase(rxBuffer.begin(),rxBuffer.begin()+5);
//        return buf;
//    }
//    else
//        return "\0";
//}

//std::string UartClass::receiveArray()
//{
//    std::lock_guard<std::mutex> lock(tex);
//    if(rxBuffer.size() >= 6)
//    {
//        std::cout<<"rxBuffer = "<<std::hex<<(int)rxBuffer.at(0)<<(int)rxBuffer.at(1)<<(int)rxBuffer.at(2)<<(int)rxBuffer.at(3)<<(int)rxBuffer.at(4)<<(int)rxBuffer.at(5)<<std::endl;
//        std::string returnString(rxBuffer.begin(),rxBuffer.begin()+5);

//        rxBuffer.erase(rxBuffer.begin(),rxBuffer.begin()+5);
//        return returnString;
//    }
//    else
//        return "\0";
//}

void UartClass::receiveThreadFunction()
{
    printf("receive array in uartclass\n");
    char *rx_buffer;
    if (uart0_filestream != -1)
    {
        rx_buffer = new char[10];
        int rx_length = 0;
        while(running)
        {
            // Read up to 255 characters from the port if they are there

            rx_length = read(uart0_filestream, (void*)rx_buffer, 9);		//Filestream, buffer to store in, number of bytes to read (max)
//            if (rx_length < 0)
//            {
//                //An error occured (will occur if there are no bytes)
//                rx_buffer[0] = '\0';
//                LOG(ERROR)<<"No bytes available in UART";
//            }
//            else if (rx_length == 0)
//            {
//                //No data waiting
//                rx_buffer[0] = '\0';
//                printf("No data in buffer\n");
//            }
//            else
            LOG(DEBUG)<<"rx_length in uartclass is: "<<std::dec<<rx_length;
            if(rx_length > 0)
            {

                //Bytes received
    //            rx_buffer[rx_length] = '\0';
                //char* end = rx_buffer + strlen( rx_buffer);

                //rxBuffer.insert(rxBuffer.end(),rx_buffer,end);
//                std::vector<char> temp (rx_buffer[0],rx_buffer[rx_length]);
//                std::string temp (rx_buffer[0],rx_buffer[rx_length]);
                std::string temp (rx_buffer);

                std::cout<<"Received: ";
                for(unsigned int i = 0; i < temp.length() ; i ++)
                {
                    std::cout<<std::hex<<(short)temp.at(i) <<" ";
                }
                std::cout<<std::dec<<std::endl;
                std::lock_guard<std::mutex> lock(tex);
                rxBuffer += temp;
                //printf("%i bytes read : %i\n", rx_length, rx_buffer);


                //std::cout<<"bytes read: "<<std::hex<<(int)rx_buffer<<std::endl;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        LOG(WARN)<<"UART Receive thread terminated";
    }
    else
        LOG(ERROR)<<"Failed to open uart";
}

