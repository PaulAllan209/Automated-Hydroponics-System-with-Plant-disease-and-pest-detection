#include <Arduino.h>
#include "./modules/communication.h"
// #include "./modules/parameter_controller.h"

Communication communcation;
String received_dat;
int CTS_pin{13};

void setup() {
  pinMode(CTS_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0){
    received_dat = Serial.readStringUntil(',');
    communcation.read_data(received_dat);
  }
}
