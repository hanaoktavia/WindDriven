
#include <TimerOne.h>

#include <LiquidCrystal.h>
#include "TimerOne.h"

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

void setup(){
  Serial.begin(9600);
  Timer1.initialize(60000000);
  attachInterrupt(0, docount, RISING);
  Timer1.attachInterrupt(timerIsr);}

void loop(){
  delay(100);
//  sig = Read(A0);
   
//  if( sig > 200) val=HIGH;
//  else val = LOW;
//  if (prev_val == 0 && val == 1){
//    cur_t = micros();
//    rpm = 1000000*60/(cur_t - t);
//    t = micros();
//    }
//  prev_val = val;

//  lcd.print(sig);
  }
