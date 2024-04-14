#include <Arduino.h>
#include "./modules/communication.h"
#include "./modules/step_motor.h"
#include <AccelStepper.h>

// Communication communication;
// String received_dat;
// int CTS_pin{13};

// Millis variables for delaying

// AccelStepper classes
AccelStepper testAxis(1, 2, 3);


void setup() {
  // communication.def_CTS_pin(CTS_pin);
  // communication.serial_begin();
  testAxis.setMaxSpeed(400);
  testAxis.setSpeed(300);
}

void loop() {
  // while (Serial.available() > 0){
  //   communication.read_data();
  //   communication.parse_data();
  //   if (communication.is_recv){
  //     communication.print_data();
  //   }
  // }
  testAxis.runSpeed();


}
