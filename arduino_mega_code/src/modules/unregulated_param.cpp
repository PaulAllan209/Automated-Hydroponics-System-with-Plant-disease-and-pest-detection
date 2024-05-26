#include <Arduino.h>
#include "parameter_controller.h"

UnregulatedParam::UnregulatedParam(Communication& comm1_input) : comm1(comm1_input){
}
void UnregulatedParam::set_pins(){
    pinMode(linear_act_DPDT_1, OUTPUT);
    pinMode(linear_act_DPDT_2, OUTPUT);
    pinMode(grow_light_1, OUTPUT);
    pinMode(grow_light_2, OUTPUT);
    pinMode(air_pump, OUTPUT);
    pinMode(exhaust_fan_1, OUTPUT);
    pinMode(exhaust_fan_2, OUTPUT);

    digitalWrite(linear_act_DPDT_1, HIGH);
    digitalWrite(linear_act_DPDT_2, HIGH);
    digitalWrite(grow_light_1, HIGH);
    digitalWrite(grow_light_2, HIGH);
    digitalWrite(air_pump, HIGH);
    digitalWrite(exhaust_fan_1, HIGH);
    digitalWrite(exhaust_fan_2, HIGH);
}
void UnregulatedParam::set_outputs(){
    // Due to the active low input of the relays. The states are reversed

    if (comm1.unregulated_param.linear_act == 1){
        digitalWrite(linear_act_DPDT_1, LOW);
        digitalWrite(linear_act_DPDT_2, LOW);
    }
    else if (comm1.unregulated_param.linear_act == 0){
        digitalWrite(linear_act_DPDT_1, HIGH);
        digitalWrite(linear_act_DPDT_2, HIGH);
    }

    if (comm1.unregulated_param.grow_light_1 == 0){
        digitalWrite(grow_light_1, LOW);
    }
    else if (comm1.unregulated_param.grow_light_1 == 1){
        digitalWrite(grow_light_1, HIGH);
    }

    if (comm1.unregulated_param.grow_light_2 == 0){
        digitalWrite(grow_light_2, LOW);
    }
    else if (comm1.unregulated_param.grow_light_2 == 1){
        digitalWrite(grow_light_2, HIGH);
    }

    if (comm1.unregulated_param.air_pump == 1){
        digitalWrite(air_pump, LOW);
    }
    else if (comm1.unregulated_param.air_pump == 0){
        digitalWrite(air_pump, HIGH);
    }

    if (comm1.unregulated_param.exhaust_fan_1 == 1){
        digitalWrite(exhaust_fan_1, LOW);
    }
    else if (comm1.unregulated_param.exhaust_fan_1 == 0){
        digitalWrite(exhaust_fan_1, HIGH);
    }

    if (comm1.unregulated_param.exhaust_fan_2 == 1){
        digitalWrite(exhaust_fan_2, LOW);
    }
    else if (comm1.unregulated_param.exhaust_fan_2 == 0){
        digitalWrite(exhaust_fan_2, HIGH);
    }


}