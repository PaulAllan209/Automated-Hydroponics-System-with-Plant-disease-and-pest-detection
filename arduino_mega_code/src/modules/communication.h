/*
communication.h

This file defines the variables used by the communication.cpp file.
*/

#pragma once

class Communication{
    public:
    Communication();
    struct RegulatedParam{
        int base_peris_pump{0};
        int acid_peris_pump{0};
        int nutriA_peris_pump {0};
        int nutriB_peris_pump {0};

        float water_pump_speed{0};

        int peltier_state{0};
        char peltier_mode{'C'};

        int solenoid{0};

        int EC_power{0};
        int pH_power{0};
    };

    struct UnregulatedParam{
        int linear_act{0};

        int grow_light_1{0};
        int grow_light_2{0};

        int air_pump{0};

        int exhaust_fan_1{0};
        int exhaust_fan_2{0};
    };

    struct StepMotors{
        // States of step motors
        int capture_plants{0}; // if it is 1 gantry will start moving and capturing the plants
        int next_plant_state{0}; // will be true if the gantry will move to next plant
        int return_home_position{0}; // if true it will return to home position
        int debug_state{0};
        int enable_pins{0};
    };

    RegulatedParam regulated_param;
    UnregulatedParam unregulated_param;
    StepMotors step_motors;

    void serial_begin(int baudrate=9600);
    void read_data();
    void parse_data();
    void print_data();

    void read_raw_data(String received_dat);
    void print_raw_data();

    // Hardware flow control methods
    void def_CTS_pin(int pin_num);
    void set_CTS_pin(bool CTS_state);

    // State if there are received data
    bool is_recv = false;

    // Variables used inside the class
    private:
    // Variables for parsing data
    char start_marker = '<';
    String tmp_data;
    static const int char_arr_size = 16;
    char char_arr[char_arr_size];
    int id_data;
    char data_contained[8];
    char* strt_ok_idx;

    String raw_data = "No data";

    // CTS pin for flow control
    int cts_pin;
};
