#include <Arduino.h>
#include "./modules/communication.h"
// #include "./modules/parameter_controller.h"

Communication communication;
String received_dat;
int CTS_pin{13};

void setup() {
  pinMode(CTS_pin, OUTPUT);
  communication.serial_begin();
}

void loop() {
  if (Serial.available() > 0){
    communication.read_data();
    communication.parse_data();
    communication.print_data();
    // communication.read_data(received_dat);
    // communication.parse_data();
  }
  // else{
  //   // delay(1000);
  // }
}
