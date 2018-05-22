#ifndef SPEEDMEASUREMENT_h
#define SPEEDMEASUREMENT_h

#include <LiquidCrystal.h>
#include "TimerOne.h"

const int rs = 12;
const int en = 11;
const int d4 = 7;
const int d5 = 6;
const int d6 = 5;
const int d7 = 4;
LiquidCrystal lcdOne (rs, en, d4, d5, d6, d7);

class SpeedMeasure
{
  public:
  SpeedMeasure(LiquidCrystal lcd): _lcd(lcd){}
  void speedInit();
  void docount();
  void timerIsr();
  void speedLoop();

  private:
  unsigned int _counter = 0;
  int _rotation = 0;
  unsigned long _time, _cur_time;
  LiquidCrystal _lcd;
 
};

extern SpeedMeasure speedOne(lcdOne);

#endif
