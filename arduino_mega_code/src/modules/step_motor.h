#pragma once
#include <MultiStepper.h>
#include <AccelStepper.h>
#include <./modules/communication.h>
#include <Arduino.h>

class StepMotor{
    public:
    Communication& comm1;
    StepMotor(Communication& comm1_input);

    // States of step motors
    int capture_plants{0}; // if it is 1 gantry will start moving and capturing the plants
    bool return_home_position{false}; // if true it will return to home position

    // Pins
    uint8_t x_axis_pulse{33};
    uint8_t x_axis_dir{34};
    uint8_t z1_axis_pulse{35};
    uint8_t z1_axis_dir{36};
    uint8_t z2_axis_pulse{37};
    uint8_t z2_axis_dir{38};
    uint8_t y_axis_pulse{39};
    uint8_t y_axis_dir{40};
    uint8_t enable_pin{41};

    // coords each plants
    // Plant 1
    long int p1_x{-4930};
    long int p1_z1{24635};
    long int p1_z2{24635};
    long int p1_y{1152};

    // Plant 2
    long int p2_x{-9564};
    long int p2_z1{24635};
    long int p2_z2{24635};
    long int p2_y{1123};

    // Plant 3
    long  int p3_x{-14990};
    long int p3_z1{24635};
    long int p3_z2{24635};
    long int p3_y{1188};

    // Plant 4
    long int p4_x{-17538};
    long int p4_z1{24635};
    long int p4_z2{24635};
    long int p4_y{4764};

    // Plant 5
    long int p5_x{-12533};
    long int p5_z1{24635};
    long int p5_z2{24635};
    long int p5_y{4177};

    // Plant 6
    long int p6_x{-7227};
    long int p6_z1{24635};
    long int p6_z2{24635};
    long int p6_y{4138};

    // Plant 7
    long int p7_x{-2328};
    long int p7_z1{24635};
    long int p7_z2{24635};
    long int p7_y{4040};

    // Plant 8
    long int p8_x{-5027};
    long int p8_z1{24635};
    long int p8_z2{24635};
    long int p8_y{6850};

    // Plant 9
    long int p9_x{-9717};
    long int p9_z1{24635};
    long int p9_z2{24635};
    long int p9_y{6991};

    // Plant 10
    long int p10_x{-14897};
    long int p10_z1{24635};
    long int p10_z2{24635};
    long int p10_y{7200};

    // for capture plants method
    bool home_pos_state{false};
    int plant_pos_debug;
    bool capture_plants_ready{false};

    // debug mode
    char dir_key;
    long positions[4];

    bool coords_is_equal = true; // state for checking if the stepper motor coords are equal to the sent by raspberry pi

    // Stepper motor speed parameters
    unsigned long time_counter1;
    unsigned long time_counter2;
    unsigned long step_speed = {10};

    int gantry_debug_state{0}; // when setting the coordinates for the plants

    // Stepper motor classes
    // (motor interface ,pulse_pin, dir_pin)
    // Apparently using curly braces in the classes fixes errors in the code
    int motor_interface{1}; // motor interface is in driver mode
    AccelStepper step_x{1, x_axis_pulse, x_axis_dir};
    AccelStepper step_z1{1, z1_axis_pulse, z1_axis_dir};
    AccelStepper step_z2{1, z2_axis_pulse, z2_axis_dir};
    AccelStepper step_y{1, y_axis_pulse, y_axis_dir};

    MultiStepper stepper_motors;

    // Limit switches pins
    int x_limit{42};
    int z_limit{43};
    int y_limit{44};

    void set_enable_pins();
    void set_limit_switches_pins();
    void set_max_speed();
    void add_stepper_motors();
    void receive_coords(int step_x, int step_y, int step_z1, int step_z2);
    void capture_all_plants();
    void capture_plant_debug();
    bool check_coords(); // returns true and sends message to serial if the coords matches with the received coords
    void debug_mode();

    void go_home_pos();
};