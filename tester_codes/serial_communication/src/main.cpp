#include <Arduino.h>

char data;
void setup() {
  Serial.begin(9600);
  
}

void loop() {
  if (Serial.available()){
    data = Serial.read();
    Serial.print(data);
  }

  
}

