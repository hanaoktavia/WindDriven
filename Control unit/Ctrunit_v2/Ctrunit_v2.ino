//#include <TimerOne.h>

#include <LiquidCrystal.h>
#include "TimerOne.h"

#define NUM_SAMPLES 10

int sum = 0;                    // sum of samples taken
unsigned char sample_count = 0; // current sample number
float voltage = 0.0;            // calculated voltage
float current = 0.0;
float resistor = 1100000.0;
float calib = 11.132;
unsigned int counter =0;
int rotation = 0;
//int sig;
//, val, rpm,
//    prev_val = 0,
//    refsig = 200;
unsigned long t, cur_t;
const int rs = 12,
          en = 11,
          d4 = 7, //5, 
          d5 = 6, //4,
          d6 = 5, //3,
          d7 = 4; //2;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

void docount(){
  counter++;}

void timerIsr(){
  Timer1.detachInterrupt();
  lcd.begin(16,2);
  
  lcd.print("IR val= ");

  int rotation = (counter / 20);
  
  lcd.print(rotation, DEC);
  Serial.print(rotation);
  
  lcd.println(" RPM");
  
  lcd.display();
  counter = 0;
  Timer1.attachInterrupt(timerIsr);
  }

void setup() {
  Serial.begin(9600);

  Timer1.initialize(60000000);
  attachInterrupt(0, docount, RISING);
  Timer1.attachInterrupt(timerIsr);
}

void loop() {
  delay(100);
  
    // take a number of analog samples and add them up
    while (sample_count < NUM_SAMPLES) {
        sum += analogRead(A2);
        sample_count++;
        delay(10);
    }
    // calculate the voltage
    // use 5.0 for a 5.0V ADC reference voltage
    // 5.015V is the calibrated reference voltage
    voltage = ((float)sum / (float)NUM_SAMPLES * 5.015) / 1024.0;
    
    // send voltage for display on Serial Monitor
    // voltage multiplied by 11 when using voltage divider that
    // divides by 11. 11.132 is the calibrated voltage divide
    // value
    current = (voltage * calib)/resistor;
    Serial.print(voltage * calib);
    Serial.println (" V");
    Serial.print(current,9);
    Serial.println(" A");
    sample_count = 0;
    sum = 0;

}
