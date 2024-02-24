#include <Arduino.h>

int length_dat{50};
char received_dat[50];


struct data_outputs{
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



void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 45){
    // received_dat2 = Serial.readStringUntil('\n');
    // Serial.println(received_dat2);

  }

}
