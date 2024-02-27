#pragma once

class Communication{
    public:
    Communication(int baud=9600);

    struct RegulatedParam{
        int base_peris_pump{0};
        int acid_peris_pump{0};
        int nutriA_peris_pump {0};
        int nutriB_peris_pump {0};

        float water_pump_speed{0};

        int peltier_state{0};
        String peltier_mode{"Cold"};

        int solenoid{0};
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
        int step_x{0};
        int step_y{0};
        int step_z1{0};
        int step_z2{0};
    };

    RegulatedParam regulated_param;
    UnregulatedParam unregulated_param;
    StepMotors step_motors;
    void read_data(String received_dat);
    void parse_data();

    private:
    int baudrate;
    int base_peris_pump;
    int acid_peris_pump;
    int nutriA_peris_pump;
    int nutriB_peris_pump;

    float water_pump_speed;

    int peltier_state;
    String peltier_mode;

    int linear_act;

    int grow_light_1;
    int grow_light_2;

    int air_pump;

    int exhaust_fan_1;
    int exhaust_fan_2;

    int solenoid;

    int step_x;
    int step_y;
    int step_z1;
    int step_z2;
};