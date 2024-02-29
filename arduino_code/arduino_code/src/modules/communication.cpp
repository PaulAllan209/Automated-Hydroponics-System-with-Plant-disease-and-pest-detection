#include <Arduino.h>
#include "./modules/communication.h"

Communication::Communication(){
}

// Initialize the serial monitor
void Communication::serial_begin(int baudrate){
  Serial.begin(baudrate);
}

// Data is read via separating it into commas
void Communication::read_data(){
  set_CTS_pin(false); // Hardware data flowcontrol
  if (Serial.read() == start_marker){
    tmp_data = Serial.readStringUntil('>');
  }
  set_CTS_pin(true);

}

// Data is separated into regulated, unregulated, and stepper motor structs
void Communication::parse_data(){
    tmp_data.toCharArray(char_arr, char_arr_size);

    // Store the data id 
    strt_ok_idx = strtok(char_arr, ",");
    id_data = atoi(strt_ok_idx);

    // Store the data itself
    strt_ok_idx = strtok(NULL, ",");
    strcpy(data_contained, strt_ok_idx);
    
    switch (id_data){
      case 100:
        regulated_param.base_peris_pump = atoi(data_contained);
        break;
      case 101:
        regulated_param.acid_peris_pump = atoi(data_contained);
        break;
      case 102:
        regulated_param.nutriA_peris_pump = atoi(data_contained);
        break;
      case 103: 
        regulated_param.nutriB_peris_pump = atoi(data_contained);
        break;
      case 104:
        regulated_param.water_pump_speed = atof(data_contained);
        break;
      case 105:
        regulated_param.peltier_state= atoi(data_contained);
        break;
      case 106:
        regulated_param.peltier_mode= peltier_mode;
        break;
      case 107:
        unregulated_param.linear_act= atoi(data_contained);
        break;
      case 108:
        unregulated_param.grow_light_1= atoi(data_contained);
        break;
      case 109:
        unregulated_param.grow_light_2= atoi(data_contained);
        break;
      case 110: 
        unregulated_param.air_pump= atoi(data_contained);
        break;
      case 111:
        unregulated_param.exhaust_fan_1= atoi(data_contained);
        break;
      case 112:
        unregulated_param.exhaust_fan_2= atoi(data_contained);
        break;
      case 113:
        regulated_param.solenoid= atoi(data_contained);
        break;
      case 114:
        step_motors.step_x= atoi(data_contained);
        break;
      case 115:
        step_motors.step_y= atoi(data_contained);
        break;
      case 116:
        step_motors.step_z1= atoi(data_contained);
        break;
      case 117:
        step_motors.step_z2= atoi(data_contained);
        break;
      
      default:
        break;
    }
}

// Method for testing the communication class
void Communication::print_data(){
  // Regulated parameters
  Serial.print("Base peris pump: ");
  Serial.println(regulated_param.base_peris_pump);
  Serial.print("Acid peris pump: ");
  Serial.println(regulated_param.acid_peris_pump);
  Serial.print("NutriA peris pump: ");
  Serial.println(regulated_param.nutriA_peris_pump);
  Serial.print("NutriB peris pump: ");
  Serial.println(regulated_param.nutriB_peris_pump);
  Serial.print("Water pump speed: ");
  Serial.println(regulated_param.water_pump_speed);
  Serial.print("Peltier state: ");
  Serial.println(regulated_param.peltier_state);
  Serial.print("Peltier mode: ");
  Serial.println(regulated_param.peltier_mode[0]);

  // Unregulated parameters
  Serial.print("Linear act: ");
  Serial.println(unregulated_param.linear_act);
  Serial.print("Grow light 1: ");
  Serial.println(unregulated_param.grow_light_1);
  Serial.print("Grow light 2: ");
  Serial.println(unregulated_param.grow_light_2);
  Serial.print("Air pump: ");
  Serial.println(unregulated_param.air_pump);
  Serial.print("Exhaust fan 1: ");
  Serial.println(unregulated_param.exhaust_fan_1);
  Serial.print("Exhaust fan 2: ");
  Serial.println(unregulated_param.exhaust_fan_2);

  // Stepper motors
  Serial.print("Step motor x: ");
  Serial.println(step_motors.step_x);

  Serial.print("Step motor y: ");
  Serial.println(step_motors.step_y);

  Serial.print("Step motor z1: ");
  Serial.println(step_motors.step_z1);

  Serial.print("Step motor z2: ");
  Serial.println(step_motors.step_z2);
}

void Communication::read_raw_data(String received_dat){
  raw_data = received_dat;
}

void Communication::print_raw_data(){
  // Serial.println(tmp_data);
  Serial.print("Data ID: ");
  Serial.println(id_data);
  Serial.print("Data contained: ");
  Serial.println(data_contained);
}


// Hardware flow control methods
void Communication::def_CTS_pin(int pin_num){
  cts_pin = pin_num;
  pinMode(pin_num, OUTPUT);
}

void Communication::set_CTS_pin(bool CTS_state){
  if (CTS_state == true){
    digitalWrite(cts_pin, HIGH);
  }
  else if (CTS_state == false){
    digitalWrite(cts_pin, LOW);
  }
}
