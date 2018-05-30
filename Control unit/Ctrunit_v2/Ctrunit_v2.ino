#include <TimerOne.h>

#include <LiquidCrystal.h>
#include "TimerOne.h"

#define NUM_SAMPLES 10

#define pin_with_pullup 8 //overvoltage ----> OV for LCD 
#define pin_with_pullup2 9 //overheating ---> OH for LCD

int sum = 0;                    // sum of samples taken
unsigned char sample_count = 0; // current sample number
double voltageS = 0.0;            // calculated voltage
double voltageB = 0.0;
double resistor = 1100000.0;
double calib = 11.132;
unsigned int counter =0;
double rotation = 0;
unsigned long t, cur_t;
const int rs = 12,
          en = 11,
          d4 = 7, //5, 
          d5 = 6, //4,
          d6 = 5, //3,
          d7 = 4; //2;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  
  pinMode(pin_with_pullup, INPUT_PULLUP);
  pinMode(pin_with_pullup2, INPUT_PULLUP);

  Timer1.initialize(60000000);
  attachInterrupt(0, docount, RISING);
  Timer1.attachInterrupt(timerIsr);
}

void docount(){
  counter++;}

void timerIsr(){
  Timer1.detachInterrupt();
  lcd.begin(16,2);
  
  lcd.print("RPM: ");

  int rotation = ((double)counter / 20.00);

  Serial.print(rotation, DEC);
   
  lcd.print(rotation, DEC);

  lcd.setCursor(0,1);
  lcd.print("Vcap: ");
  lcd.print(voltageS * calib);
  lcd.print("V");

  lcd.setCursor(12,0);
  if(digitalRead(pin_with_pullup) == HIGH)
  {lcd.print("OV");}
  else{;}
  if(digitalRead(pin_with_pullup2) == HIGH)
  {lcd.print("OH");}
  else{;}
  
  lcd.display();
  counter = 0;
  Timer1.attachInterrupt(timerIsr);
  }

void loop() {

    double digitalT,digitalV = 0.0;
    double sensorVal = digitalRead(pin_with_pullup);
    double sensorVal2 = digitalRead(pin_with_pullup2);

    if(sensorVal == HIGH)
    {
      //For debug use --> Serial.print("ATTENTION! OVERVOLTAGE!!");
      digitalT = 1.0;
    }else{digitalT = 0.0;}
    if(sensorVal2 == HIGH)
    {
      //For debug use --> Serial.print("ATTENTION! OVERHEATING!!");
      digitalV = 1.0;
    }else{digitalV = 0.0;}

    // take a number of analog samples and add them up
    while (sample_count < NUM_SAMPLES) {
        sum += analogRead(A2);
        sample_count++;
        delay(10);
    }
    // Calculate the voltage. Use 5.0 for a 5.0V ADC reference voltage. 5.015V is the calibrated reference voltage
    voltageS = ((float)sum / (float)NUM_SAMPLES * 5.015) / 1024.0;
    voltageB = 10.0;
    
    // send voltage for display on Serial Monitor. Voltage multiplied by 11 when using voltage divider that divides by 11. 11.132 is the calibrated voltage divide value
    //For current measurement use the following formula: current = (voltage * calib)/resistor;
    //For terminal debug uncomment this line and press enter --> //Serial.println (" V");
    //For terminal debug uncomment this line and press enter --> //Serial.print(current,9); Serial.println(" A");
    
    //Printing the voltage value
    Serial.print(voltageB);
    Serial.print(",");
    Serial.print(voltageS * calib);
    Serial.print(",");
    Serial.print(digitalT);
    Serial.print(",");
    Serial.print(digitalV);
    Serial.print(",");
    Serial.flush();

    delay(500);
    
    sample_count = 0;
    sum = 0;

}
