#include "voltMeasurement.h"

void voltLoop(){
  
    // take a number of analog samples and add them up
    while (_sample_count < NUM_SAMPLES) {
        _sum += analogRead(A2);
        _sample_count++;
        delay(10);
    }
    // calculate the voltage
    // use 5.0 for a 5.0V ADC reference voltage
    // 5.015V is the calibrated reference voltage
    _voltage = ((float)_sum / (float)NUM_SAMPLES * 5.015) / 1024.0;
    // send voltage for display on Serial Monitor
    // voltage multiplied by 11 when using voltage divider that
    // divides by 11. 11.132 is the calibrated voltage divide
    // value
    current = (_voltage * _calib)/_resistor;
    Serial.print(_voltage * _calib);
    Serial.println (" V");
    Serial.print(_current,9);
    Serial.println(" A");
    _sample_count = 0;
    _sum = 0;
 }
