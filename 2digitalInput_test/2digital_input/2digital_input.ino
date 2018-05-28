#define pin_with_pullup 8 //overvoltage
#define pin_with_pullup2 9 //overheating

void setup() {
  Serial.begin(9600);
  pinMode(pin_with_pullup, INPUT_PULLUP);
  pinMode(pin_with_pullup2, INPUT_PULLUP);

}

void loop() {
  int sensorVal = digitalRead(pin_with_pullup);
  int sensorVal2 = digitalRead(pin_with_pullup2);

  //Debug code
  Serial.print("Debug --> Digitalpin1 value -->");
  Serial.println(sensorVal);
  Serial.print("Debug --> Digitalpin2 value -->");
  Serial.println(sensorVal2);

  if(sensorVal == HIGH)
  {
    Serial.print("ATTENTION! OVERVOLTAGE!!");
  }else{;}
  if(sensorVal2 == HIGH)
  {
    Serial.print("ATTENTION! OVERHEATING!!");
  }else{;}

}
