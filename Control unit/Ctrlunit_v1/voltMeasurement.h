#ifndef VOLTMEASUREMENT_h
#define VOLTMEASUREMENT_h

#include <LiquidCrystal.h>
#include "TimerOne.h"

#define NUM_SAMPLES 10

class VoltMeasure
{
  public:
  void voltLoop();

  private:
  int _sum = 0;                    // sum of samples taken
  unsigned char _sample_count = 0; // current sample number
  float _voltage = 0.0;            // calculated voltage
  float _current = 0.0;
  float _resistor = 1100000.0;
  float _calib = 11.132;

};

//extern TimerOne Timer1;
#endif
