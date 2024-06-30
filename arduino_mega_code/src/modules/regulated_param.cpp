/*
regulated_param.cpp

This file contains the code for controlling the four peristaltic pumps,
turning the peltier cooler on or off, setting the voltage for the water
inlet pump, and the power for both the pH and EC sensor.
*/

#include <Arduino.h>
#include "parameter_controller.h"

void RegulatedParam::read_data(String received_dat){ // for debugging purposes
    if (received_dat == static_cast<String>("a")){
    base_peris_pump = Serial.readStringUntil(',').toInt();
    Serial.println(base_peris_pump);
    }

    else if (received_dat == static_cast<String>("b")){
    acid_peris_pump = Serial.readStringUntil(',').toInt();
    // Serial.print("b: ");
    Serial.println(acid_peris_pump);
    }

    else if (received_dat == static_cast<String>("c")){
    nutriA_peris_pump = Serial.readStringUntil(',').toInt();
    Serial.println(nutriA_peris_pump);
    }

    else if (received_dat == static_cast<String>("d")){
    nutriB_peris_pump = Serial.readStringUntil(',').toInt();
    Serial.println(nutriB_peris_pump);
    }

    else if (received_dat == static_cast<String>("e")){
    water_pump_speed = Serial.readStringUntil(',').toFloat();
    Serial.println(water_pump_speed);
    }

    else if (received_dat == static_cast<String>("f")){
    peltier_state = Serial.readStringUntil(',').toInt();
    Serial.println(peltier_state);
    }

    else if (received_dat == static_cast<String>("g")){
    peltier_mode = Serial.readStringUntil(',');
    Serial.println(peltier_mode);
    }

    else if (received_dat == static_cast<String>("n")){
    solenoid = Serial.readStringUntil(',').toInt();
    Serial.println(solenoid);
    }
}

void RegulatedParam::control_pH(){
    int RVbase_pump = analogRead(ARbase_peris_pump);
    int RVacid_pump = analogRead(ARacid_peris_pump);


    if (RVbase_pump > 200){
        digitalWrite(DObase_peris_pump, HIGH);
    }
    if (RVacid_pump > 200){
        digitalWrite(DOacid_peris_pump, HIGH);
    }


    if (RVbase_pump < 200){
        digitalWrite(DObase_peris_pump, LOW);
    }
    if (RVacid_pump < 200){
        digitalWrite(DOacid_peris_pump, LOW);
    }
}

void RegulatedParam::control_EC(){
    int RVnutriA_pump = analogRead(ARnutriA_peris_pump);
    int RVnutriB_pump = analogRead(ARnutriB_peris_pump);

    if (RVnutriA_pump > 200){
        digitalWrite(DOnutriA_peris_pump, HIGH);
    }
    if (RVnutriB_pump > 200){
        digitalWrite(DOnutriB_peris_pump, HIGH);
    }

    if (RVnutriA_pump < 200){
        digitalWrite(DOnutriA_peris_pump, LOW);
    }
    if (RVnutriB_pump < 200){
        digitalWrite(DOnutriB_peris_pump, LOW);
    }
}

void RegulatedParam::control_water_temp(){
    // peltier pin is 28
    if (comm1.regulated_param.peltier_state==0){
        digitalWrite(peltier_DPDT_1, HIGH);
        analogWrite(AOwater_pump_peltier, 0);
    }
    if (comm1.regulated_param.peltier_state==1){
        digitalWrite(peltier_DPDT_1, LOW);
        analogWrite(AOwater_pump_peltier, 120);
    }
}

void RegulatedParam::control_water_flow_rate(){
    int flow_val = analogRead(ARwater_pump);
    int mapped_val = map(flow_val, 0, 574, 0, 255);
    if (mapped_val > 100){
        analogWrite(AOwater_pump, 220);
    }

    else if (mapped_val < 100){
        analogWrite(AOwater_pump, 0);
    }
}

void RegulatedParam::set_pins(){
    // Analog pins read
    pinMode(ARbase_peris_pump, INPUT);
    pinMode(ARacid_peris_pump, INPUT);
    pinMode(ARnutriA_peris_pump, INPUT);
    pinMode(ARnutriB_peris_pump, INPUT);
    pinMode(ARwater_pump, INPUT);

    // Analog pins out
    pinMode(DObase_peris_pump, OUTPUT);
    pinMode(DOacid_peris_pump, OUTPUT);
    pinMode(DOnutriA_peris_pump, OUTPUT);
    pinMode(DOnutriB_peris_pump, OUTPUT);
    pinMode(AOwater_pump, OUTPUT);
    pinMode(AOwater_pump_peltier, OUTPUT);

    // Digital pins out
    pinMode(peltier_DPDT_1, OUTPUT);
    pinMode(solenoid_valve, OUTPUT);
    pinMode(EC_power_p, OUTPUT);
    pinMode(pH_power_p, OUTPUT);
}

void RegulatedParam::EC_and_pH_power(){
    if (comm1.regulated_param.EC_power == 0){
        digitalWrite(EC_power_p, HIGH);
    }
    else if (comm1.regulated_param.EC_power == 1){
        digitalWrite(EC_power_p, LOW);
    }

    if (comm1.regulated_param.pH_power == 0){
        digitalWrite(pH_power_p, HIGH);
    }
    else if (comm1.regulated_param.pH_power == 1){
        digitalWrite(pH_power_p, LOW);
    }
}

void RegulatedParam::test_print(){
    Serial.println(comm1.unregulated_param.linear_act);
}
RegulatedParam::RegulatedParam(Communication& comm1_input) : comm1(comm1_input){
}

