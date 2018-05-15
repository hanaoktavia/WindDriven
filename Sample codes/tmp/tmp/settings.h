#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

/********************************************************
 *
 * The namespace MQTTsettings contains settings for the
 * MQTT topics.
 *
 * ******************************************************/
namespace MQTTSettings {
// Nodes
    const std::string windspeed             = "windspeed";
    const std::string absoluteWindDirection = "winddirection";
// Car
    const std::string drivenDistane         = "drivendistance";// na
    const std::string pedometer             = "pedometer";
    const std::string carDirection          = "direction";
    const std::string correctionVector      = "correctionvector";
    const std::string carCondensorVolatage  = "condensorvolatage";
    const std::string carPowerConsumed      = "powerconsumed";
}

namespace serialSequence {
    const int FIRST     = 0x55;
    const int SECOND    = 0x77;
    const int THIRD     = 0x99;

}

namespace serial {
    const int CAR   = 0x09;
    const int CREW  = 0x0a;
    const int NODE1 = 0x01;
    const int NODE2 = 0x02;
    const int NODE3 = 0x03;
    const int NODE4 = 0x04;
    const int NODE5 = 0x05;
    const int NODE6 = 0x06;
    const int NODE7 = 0x07;
    const int NODE8 = 0x08;

    const int SENSOR = 0x80;
    const int ACTOR  = 0x90;

    const int windspeed             = 0x0b;
    const int absoluteWindDirection = 0x0c;
    //const int drivenDistane         = 0x00;


    const int pedometer             = 0x17;
    const int carDirection          = 0x16;
    const int correctionVector      = 0x18;
    const int carCondensorVolatage  = 0x1A;
    const int carPowerConsumed      = 0x19;

    const int CAR_KEY   = 0x09;
    const int CREW_KEY  = 0x0a;
    const int NODE1_KEY = 0x01;
    const int NODE2_KEY = 0x02;
    const int NODE3_KEY = 0x03;
    const int NODE4_KEY = 0x04;
    const int NODE5_KEY = 0x05;
    const int NODE6_KEY = 0x06;
    const int NODE7_KEY = 0x07;
    const int NODE8_KEY = 0x08;
}

#endif // SETTINGS_H
