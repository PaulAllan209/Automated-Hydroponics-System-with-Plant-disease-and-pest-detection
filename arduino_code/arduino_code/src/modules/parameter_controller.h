#pragma once
#include <Arduino.h>

class RegulatedParam{
    public:
    int base_peris_pump{0};
    int acid_peris_pump{0};
    int nutriA_peris_pump{0};
    int nutriB_peris_pump{0};
    float water_pump_speed{0};
    int peltier_state{0};
    String peltier_mode{"Cold"};
    int solenoid{0};
    void read_data(String received_dat);
    void control_pH();
    void control_EC();
    void control_water_temp();
    void control_water_level();
};

class UnregulatedParam{
};
