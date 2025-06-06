/*
parameter_controller.h

This file defines the variables used by regulated_param.cpp and
unregulated_param.cpp.
*/

#pragma once
#include <Arduino.h>
#include "./modules/communication.h"

class RegulatedParam{
    public:
    Communication& comm1;
    RegulatedParam(Communication& comm1_input);

    // pin numbers analog read
    int ARbase_peris_pump{54};
    int ARacid_peris_pump{55};
    int ARnutriA_peris_pump{56};
    int ARnutriB_peris_pump{57};
    int ARwater_pump{58};

    // pin numbers digital out
    int DObase_peris_pump{53};
    int DOacid_peris_pump{52};
    int DOnutriA_peris_pump{50};
    int DOnutriB_peris_pump{49};
    int AOwater_pump{2};
    int AOwater_pump_peltier{3};

    int peltier_DPDT_1{28};
    int EC_power_p{29};
    int pH_power_p{30};
    int solenoid_valve{31};


    // placeholders for printing the values (will be soon deleted due to changes in the pumps code logic)
    int base_peris_pump{0};
    int acid_peris_pump{0};
    int nutriA_peris_pump{0};
    int nutriB_peris_pump{0};
    int water_pump{0};
    int water_pump_speed{0};

    int peltier_state{0};
    String peltier_mode{"Cold"};
    int solenoid{0};
    void read_data(String received_dat);

// The peris pump of these will receive analog signals from the raspberry pi
    void control_pH();
    void control_EC();

    void control_water_temp();
    void control_water_level();
    void control_water_flow_rate();

    void set_pins();
    void test_print();

    void EC_and_pH_power();
};

class UnregulatedParam{
    public:
    Communication& comm1;
    UnregulatedParam(Communication& comm1_input);

    // pin numbers
    int linear_act_DPDT_1{26};
    int linear_act_DPDT_2{27};
    int grow_light_1{24};
    int grow_light_2{23};
    int grow_light_conventional{20};
    int air_pump{22};
    int exhaust_fan_1{25};
    int exhaust_fan_2{21};

    void set_pins();
    void set_outputs();
};
