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
}

void RegulatedParam::control_EC(){
}

void RegulatedParam::control_water_temp(){
}

void RegulatedParam::control_water_level(){
}
