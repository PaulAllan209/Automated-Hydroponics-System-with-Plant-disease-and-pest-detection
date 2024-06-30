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
    long int z_axis{26773};
    long int p1_x{-3693};
    long int p1_z1{z_axis};
    long int p1_z2{z_axis};
    long int p1_y{908};

    // Plant 2
    long int p2_x{-8478};
    long int p2_z1{z_axis};
    long int p2_z2{z_axis};
    long int p2_y{945};

    // Plant 3
    long  int p3_x{-13629};
    long int p3_z1{z_axis};
    long int p3_z2{z_axis};
    long int p3_y{841};

    // Plant 4
    long int p4_x{-16210};
    long int p4_z1{z_axis};
    long int p4_z2{z_axis};
    long int p4_y{4073};

    // Plant 5
    long int p5_x{-11163};
    long int p5_z1{z_axis};
    long int p5_z2{z_axis};
    long int p5_y{3946};

    // Plant 6
    long int p6_x{-6224};
    long int p6_z1{z_axis};
    long int p6_z2{z_axis};
    long int p6_y{3955};

    // Plant 7
    long int p7_x{-1222};
    long int p7_z1{z_axis};
    long int p7_z2{z_axis};
    long int p7_y{3994};

    // Plant 8
    long int p8_x{-3556};
    long int p8_z1{z_axis};
    long int p8_z2{z_axis};
    long int p8_y{6759};

    // Plant 9
    long int p9_x{-8625};
    long int p9_z1{z_axis};
    long int p9_z2{z_axis};
    long int p9_y{6800};

    // Plant 10
    long int p10_x{-13676};
    long int p10_z1{z_axis};
    long int p10_z2{z_axis};
    long int p10_y{6803};

    // for capture plants method
    bool home_pos_state{false};
    int plant_pos_debug;
    bool capture_plants_ready{false};
    char capture_plants_debug_key;
    bool capture_plants_debug{false};

    // debug mode
    char dir_key;
    long positions[4];
    char plant_pos;
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
    void enable_pins_state();
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