#include <LiquidCrystal.h>
#include "TimerOne.h"
#include "SpeedMeasurement.h"

/*const int rs = 12;
const int en = 11;
const int d4 = 7;
const int d5 = 6;
const int d6 = 5;
const int d7 = 4;
LiquidCrystal lcdOne (rs, en, d4, d5, d6, d7);
*/

void setup() {
    Serial.begin(9600);
    speedOne.speedInit();
}

void loop() {
  speedOne.speedLoop();
  
}
