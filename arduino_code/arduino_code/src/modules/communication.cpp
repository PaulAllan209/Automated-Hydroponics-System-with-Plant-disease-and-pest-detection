#include <Arduino.h>
#include "./modules/communication.h"

Communication::Communication(){
}

// Initialize the serial monitor
void Communication::serial_begin(int baudrate){
  Serial.begin(baudrate);
}

// Data is read via separating it into commas
void Communication::read_data(String received_dat){
    if (received_dat == static_cast<String>("a")){
      base_peris_pump = Serial.readStringUntil(',').toInt();
    }

    else if (received_dat == static_cast<String>("b")){
      acid_peris_pump = Serial.readStringUntil(',').toInt();
    }

    else if (received_dat == static_cast<String>("c")){
      nutriA_peris_pump = Serial.readStringUntil(',').toInt();
    }

    else if (received_dat == static_cast<String>("d")){
      nutriB_peris_pump = Serial.readStringUntil(',').toInt();
    }

    else if (received_dat == static_cast<String>("e")){
      water_pump_speed = Serial.readStringUntil(',').toFloat();
    }

    else if (received_dat == static_cast<String>("f")){
      peltier_state = Serial.readStringUntil(',').toInt();
    }

    else if (received_dat == static_cast<String>("g")){
      peltier_mode = Serial.readStringUntil(',');
    }

    else if (received_dat == static_cast<String>("h")){
      linear_act = Serial.readStringUntil(',').toInt();
    }

    else if (received_dat == static_cast<String>("i")){
      grow_light_1 = Serial.readStringUntil(',').toInt();
    }

    else if (received_dat == static_cast<String>("j")){
      grow_light_2 = Serial.readStringUntil(',').toInt();
    }

    else if (received_dat == static_cast<String>("k")){
      air_pump = Serial.readStringUntil(',').toInt();
    }
    
    else if (received_dat == static_cast<String>("l")){
      exhaust_fan_1 = Serial.readStringUntil(',').toInt();
    }

    else if (received_dat == static_cast<String>("m")){
      exhaust_fan_2 = Serial.readStringUntil(',').toInt();
    }

    else if (received_dat == static_cast<String>("n")){
      solenoid = Serial.readStringUntil(',').toInt();
    }

    else if (received_dat == static_cast<String>("o")){
      step_x = Serial.readStringUntil(',').toInt();
    }

    else if (received_dat == static_cast<String>("p")){
      step_y = Serial.readStringUntil(',').toInt();
    }

    else if (received_dat == static_cast<String>("q")){
      step_z1 = Serial.readStringUntil(',').toInt();
    }

    else if (received_dat == static_cast<String>("r")){
      step_z2 = Serial.readStringUntil(',').toInt();
    }
}

// Data is separated into regulated, unregulated, and stepper motor structs
void Communication::parse_data(){
    regulated_param.base_peris_pump = base_peris_pump;
    regulated_param.acid_peris_pump = acid_peris_pump;
    regulated_param.nutriA_peris_pump = nutriA_peris_pump;
    regulated_param.nutriB_peris_pump = nutriB_peris_pump;
    regulated_param.water_pump_speed = water_pump_speed;
    regulated_param.peltier_state= peltier_state;
    regulated_param.peltier_mode= peltier_mode;

    unregulated_param.linear_act= linear_act;
    unregulated_param.grow_light_1= grow_light_1;
    unregulated_param.grow_light_2= grow_light_2;
    unregulated_param.air_pump= air_pump;
    unregulated_param.exhaust_fan_1= exhaust_fan_1;
    unregulated_param.exhaust_fan_2= exhaust_fan_2;

    regulated_param.solenoid= solenoid;

    step_motors.step_x= step_x;
    step_motors.step_y= step_y;
    step_motors.step_z1= step_z1;
    step_motors.step_z2= step_z2;
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
  Serial.println(regulated_param.peltier_mode);

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
