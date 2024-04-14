#pragma once
#include <Arduino.h>
#include "./modules/communication.h"


class RegulatedParam{
    public:
    Communication& comm1;
    RegulatedParam(Communication& comm1_input);

    // pin numbers analog read
    int base_peris_pump{54};
    int acid_peris_pump{55};
    int nutriA_peris_pump{56};
    int nutriB_peris_pump{57};
    int water_pump{58};

    float water_pump_speed{0};

    int peltier_state{0};
    String peltier_mode{"Cold"};
    int solenoid{0};
    void read_data(String received_dat);

// The peris pump of these will receive analog signals from the raspberry pi
    void control_pH();
    void control_EC();

    void control_water_temp();
    void control_water_level();

    void set_pins();
    void test_print();
};

class UnregulatedParam{
    public:
    Communication& comm1;
    UnregulatedParam(Communication& comm1_input);

    // pin numbers
    int linear_act{21};
    int grow_light_1{24};
    int grow_light_2{23};
    int air_pump{22};
    int exhaust_fan_1{25};
    int exhaust_fan_2{26};

    void set_pins();
    void set_outputs();
};
