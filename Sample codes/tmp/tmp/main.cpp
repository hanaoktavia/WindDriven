#include "mainwindow.h"
#include <QApplication>
#include <QSizePolicy>

#include "BasicFunctionality/topicsimulator.h"
#include "BasicFunctionality/sensorfactory.h"
#include "log.h"

#include "BasicFunctionality/uarttranslator.h"
#include "BasicFunctionality/uartclass.h"

//#define FILESIM

int applicationLoop(MainWindow &mainWindow);
int main(int argc, char *argv[])
{
    LOGsettings::toCout = true;
    LOG(INFO)<<"Programm started";
    // Setting up the Basic Functionality
#ifdef FILESIM
    TopicSimulator theSubscriber(SensorFactory::theSensorFactory());
#else
    UartClass uart;
    UartTranslator translator(SensorFactory::theSensorFactory(),uart);
    translator.start();
#endif
    // Setting up the GUI
    QApplication qApplication(argc, argv);
    //MainWindow mainWindow(SensorFactory::theSensorFactory(), NULL);
    MainWindow mainWindow(SensorFactory::theSensorFactory());
    mainWindow.show();
    qApplication.exec();

    // Infinite application loop
    return applicationLoop(mainWindow);
}

int applicationLoop(MainWindow &mainWindow)
{
    while(mainWindow.isVisible())
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    return 0;
}
