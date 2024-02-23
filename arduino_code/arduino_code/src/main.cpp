#include <Arduino.h>

char received_dat;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0){
    received_dat = Serial.read();
    Serial.println(received_dat);
  }
  

}

