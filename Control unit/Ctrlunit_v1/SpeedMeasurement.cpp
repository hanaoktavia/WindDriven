#include "SpeedMeasurement.h"
#include <LiquidCrystal.h>
#include "TimerOne.h"

void SpeedMeasure::speedInit(){
  Timer1.initialize(60000000);
  attachInterrupt(0, docount, RISING);
  Timer1.attachInterrupt(timerIsr(_lcd));}

void SpeedMeasure::docount(){
  _counter++;
  }

void SpeedMeasure::timerIsr()
  Serial.begin(9600);
  Timer1.detachInterrupt();
  _lcd.begin(16,2);
  
  _lcd.print("IR val= ");

  _rotation = (_counter / 20);
  
  _lcd.print(_rotation, DEC);
  Serial.print(_rotation);
  
  _lcd.println(" RPM");
  
  _lcd.display();
  _counter = 0;
  Timer1.attachInterrupt(timerIsr);
  }

void SpeedMeasure::speedLoop(){
    delay(100);
}
