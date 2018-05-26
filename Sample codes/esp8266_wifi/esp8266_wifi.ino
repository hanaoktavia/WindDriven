#include <SoftwareSerial.h>

//#define RX 2    // 0
//#define TX 3    // 1
SoftwareSerial esp8266(2, 3); 

void setup() {

  Serial.begin(9600);
  esp8266.begin(9600);  //esp module baude rate @ 9600bps
}

void loop() {

  if(esp8266.available()) //check if the esp is sending a message
  {
    while(esp8266.available())
    {
      // The esp has data so display its output to the serial window
      char c  = esp8266.read(); // read the next character
      Serial.write(c);
      }
  }

   if(Serial.available()){
    // A delay so that all the message's character is read
    delay(1000);
    String command = "test command :)";

    //read the command character by character
    while(Serial.available())
    { 
      command += (char)Serial.read(); // read the command character by character
      }
      esp8266.println(command); // send the read character to the esp8266
    }
}
