#include <Arduino.h>
#include "parameter_controller.h"

void RegulatedParam::read_data(String received_dat){
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
    else if (RVacid_pump > 200){
        digitalWrite(DOacid_peris_pump, HIGH);
    }


    if (RVbase_pump < 200){
        digitalWrite(DObase_peris_pump, LOW);
    }
    else if (RVacid_pump < 200){
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
}

void RegulatedParam::control_water_level(){
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
    pinMode(peltier_DPDT_2, OUTPUT);
    pinMode(peltier_switch, OUTPUT);
    pinMode(solenoid_valve, OUTPUT);
}

void RegulatedParam::test_print(){
    Serial.println(comm1.unregulated_param.linear_act);
}
RegulatedParam::RegulatedParam(Communication& comm1_input) : comm1(comm1_input){
}

