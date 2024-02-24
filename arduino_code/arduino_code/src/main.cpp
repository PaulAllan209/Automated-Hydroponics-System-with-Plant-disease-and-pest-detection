#include <Arduino.h>

struct DataOutputs{
  int base_peris_pump{0};
  int acid_peris_pump{0};
  int nutriA_peris_pump {0};
  int nutriB_peris_pump {0};

  float water_pump_speed{0};

  int peltier_state{0};
  String peltier_mode{"Cold"};

  int linear_act{0};

  int grow_light_1{0};
  int grow_light_2{0};

  int air_pump{0};

  int exhaust_fan_1{0};
  int exhaust_fan_2{0};

  int solenoid{0};

  int step_x{0};
  int step_y{0};
  int step_z1{0};
  int step_z2{0};
};


void read_data(String received_dat, DataOutputs data_outputs){
  if (received_dat == static_cast<String>("a")){
      data_outputs.base_peris_pump = Serial.readStringUntil(',').toInt();
      Serial.println(data_outputs.base_peris_pump);
    }

    else if (received_dat == static_cast<String>("b")){
      data_outputs.acid_peris_pump = Serial.readStringUntil(',').toInt();
      Serial.println(data_outputs.acid_peris_pump);
    }

    else if (received_dat == static_cast<String>("c")){
      data_outputs.nutriA_peris_pump = Serial.readStringUntil(',').toInt();
      Serial.println(data_outputs.nutriA_peris_pump);
    }

    else if (received_dat == static_cast<String>("d")){
      data_outputs.nutriB_peris_pump = Serial.readStringUntil(',').toInt();
      Serial.println(data_outputs.nutriB_peris_pump);
    }

    else if (received_dat == static_cast<String>("e")){
      data_outputs.water_pump_speed = Serial.readStringUntil(',').toFloat();
      Serial.println(data_outputs.water_pump_speed);
    }

    else if (received_dat == static_cast<String>("f")){
      data_outputs.peltier_state = Serial.readStringUntil(',').toInt();
      Serial.println(data_outputs.peltier_state);
    }

    else if (received_dat == static_cast<String>("g")){
      data_outputs.peltier_mode = Serial.readStringUntil(',');
      Serial.println(data_outputs.peltier_mode);
    }

    else if (received_dat == static_cast<String>("h")){
      data_outputs.linear_act = Serial.readStringUntil(',').toInt();
      Serial.println(data_outputs.linear_act);
    }

    else if (received_dat == static_cast<String>("i")){
      data_outputs.grow_light_1 = Serial.readStringUntil(',').toInt();
      Serial.println(data_outputs.grow_light_1);
    }

    else if (received_dat == static_cast<String>("j")){
      data_outputs.grow_light_2 = Serial.readStringUntil(',').toInt();
      Serial.println(data_outputs.grow_light_2);
    }

    else if (received_dat == static_cast<String>("k")){
      data_outputs.air_pump = Serial.readStringUntil(',').toInt();
      Serial.println(data_outputs.air_pump);
    }
    
    else if (received_dat == static_cast<String>("l")){
      data_outputs.exhaust_fan_1 = Serial.readStringUntil(',').toInt();
      Serial.println(data_outputs.exhaust_fan_1);
    }

    else if (received_dat == static_cast<String>("m")){
      data_outputs.exhaust_fan_2 = Serial.readStringUntil(',').toInt();
      Serial.println(data_outputs.exhaust_fan_2);
    }

    else if (received_dat == static_cast<String>("n")){
      data_outputs.solenoid = Serial.readStringUntil(',').toInt();
      Serial.println(data_outputs.solenoid);
    }

    else if (received_dat == static_cast<String>("o")){
      data_outputs.step_x = Serial.readStringUntil(',').toInt();
      Serial.println(data_outputs.step_x);
    }

    else if (received_dat == static_cast<String>("p")){
      data_outputs.step_y = Serial.readStringUntil(',').toInt();
      Serial.println(data_outputs.step_y);
    }

    else if (received_dat == static_cast<String>("q")){
      data_outputs.step_z1 = Serial.readStringUntil(',').toInt();
      Serial.println(data_outputs.step_z1);
    }

    else if (received_dat == static_cast<String>("r")){
      data_outputs.step_z2 = Serial.readStringUntil(',').toInt();
      Serial.println(data_outputs.step_z2);
    }

}

String received_dat;
DataOutputs data_outputs;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0){
    received_dat = Serial.readStringUntil(',');

    read_data(received_dat, data_outputs);

    
  }
}
