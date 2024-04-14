#include <Arduino.h>


int counter = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  delay(1000);
  Serial.print("wowmagic");
  Serial.println(counter);
  counter++;
  delay(1000);
  
}