#include <Arduino.h>
#include "./modules/communication.h"
#include "./modules/step_motor.h"
#include "./modules/parameter_controller.h"

static Communication communication;
RegulatedParam RegParam(communication); //TODO: This line is causing problems with the communication protocol
UnregulatedParam UnregParam(communication);
String received_dat;
int CTS_pin{7};

// Millis variables for delaying


void setup() {
  communication.def_CTS_pin(CTS_pin);
  communication.serial_begin();
  RegParam.set_pins();
  UnregParam.set_pins();

  pinMode(13, OUTPUT);
}

void loop() {
  while (Serial1.available() > 0){
    communication.read_data();
    communication.parse_data();
    if (communication.is_recv){
      communication.print_data();
      RegParam.test_print();
      UnregParam.set_outputs();
    }
  }
  RegParam.control_pH();
  RegParam.control_EC();



  // delay(1000);
  // delay(500);
  // analogWrite(13, 0);


}
