#include <Arduino.h>
#include "./modules/communication.h"
#include "./modules/step_motor.h"
#include "./modules/parameter_controller.h"

static Communication communication;
StepMotor all_motors(communication);
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

  // Stepper motor part
  all_motors.gantry_debug_state = true;
  all_motors.set_enable_pins();
  all_motors.set_limit_switches_pins();
  all_motors.set_max_speed();
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

  // Motor part
  all_motors.debug_mode();
  all_motors.capture_all_plants();
  
  RegParam.control_pH();
  RegParam.control_EC();
  RegParam.control_water_flow_rate();
  RegParam.control_water_temp();





  // delay(1000);
  // delay(500);
  // analogWrite(13, 0);


}
