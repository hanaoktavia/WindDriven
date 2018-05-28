#include <TimerOne.h>

#include <LiquidCrystal.h>
#include "TimerOne.h"

#define NUM_SAMPLES 10
#define LCD_BACKLIGHT A4

#define pin_with_pullup 8 //overvoltage ----> OV for LCD 
#define pin_with_pullup2 9 //overheating ---> OH for LCD

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
  
  lcd.print("RPM: ");

  int rotation = (counter / 20);

  Serial.print(rotation, DEC);
  Serial.print(",");
   
  lcd.print(rotation, DEC);

  lcd.setCursor(0,1);
  lcd.print("Vcap: ");
  lcd.print(voltage * calib);
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

void setup() {
  Serial.begin(9600);
  
  pinMode(pin_with_pullup, INPUT_PULLUP);
  pinMode(pin_with_pullup2, INPUT_PULLUP);

  pinMode(LCD_BACKLIGHT, OUTPUT);

  Timer1.initialize(60000000);
  attachInterrupt(0, docount, RISING);
  Timer1.attachInterrupt(timerIsr);
}

void loop() {
  //Printing the RPM
  
  int sensorVal = digitalRead(pin_with_pullup);
  int sensorVal2 = digitalRead(pin_with_pullup2);

  //Debug code
//  Serial.print("Debug --> AnalogRead -->");
//  Serial.println(analogRead(A2));
//  Serial.print("Debug --> Digitalpin1 value -->");
//  Serial.println(sensorVal);
//  Serial.print("Debug --> Digitalpin2 value -->");
//  Serial.println(sensorVal2);

  if(sensorVal == HIGH)
  {
    //For debug use --> Serial.print("ATTENTION! OVERVOLTAGE!!");
    Serial.print(sensorVal);
    Serial.print(",");
    Serial.flush();
  }else{;}
  if(sensorVal2 == HIGH)
  {
    //For debug use --> Serial.print("ATTENTION! OVERHEATING!!");
    Serial.print(sensorVal2);
    Serial.print(",");
    Serial.flush();
  }else{;}

  digitalWrite(LCD_BACKLIGHT, HIGH);
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
    //For current measurement use the following formula: current = (voltage * calib)/resistor;
    //For terminal debug uncomment this line and press enter --> //Serial.println (" V");
    //For terminal debug uncomment this line and press enter --> //Serial.print(current,9); Serial.println(" A");
    //Printing the voltage value
    Serial.print(voltage * calib);
    Serial.print(",");
    Serial.flush();

//    int rotation = (counter / 20);
    //Serial.print(analogRead(A0));
    
    sample_count = 0;
    sum = 0;

    delay(1000);

}
