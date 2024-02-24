#include <Arduino.h>

String data;
void setup() {
  Serial.begin(9600);
  
}

void loop() {
  if (Serial.available()){
    data = Serial.readStringUntil(',');
    Serial.print(data);
  }

  
}

