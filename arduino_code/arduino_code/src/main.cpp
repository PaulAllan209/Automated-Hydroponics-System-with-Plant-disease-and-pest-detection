#include <Arduino.h>
#include "./modules/communication.h"
// #include "./modules/parameter_controller.h"

Communication communication;
String received_dat;
int CTS_pin{13};

// Millis variables for delaying


void setup() {
  communication.def_CTS_pin(CTS_pin);
  communication.serial_begin();
}

void loop() {
  while (Serial.available() > 0){
    communication.read_data();
    communication.parse_data();
    if (communication.is_recv){
      communication.print_data();
    }
  }
}
