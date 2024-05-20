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
    int next_plant_state{0}; // will be true if the gantry will move to next plant
    int return_home_position{0}; // if true it will return to home position

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
    int p1_x;
    int p1_z1;
    int p1_z2;
    int p1_y;

    // Plant 2
    int p2_x{-30};
    int p2_z1{200};
    int p2_z2{200};
    int p2_y{30};

    // Plant 3
    int p3_x;
    int p3_z1;
    int p3_z2;
    int p3_y;

    // Plant 4
    int p4_x;
    int p4_z1;
    int p4_z2;
    int p4_y;

    // Plant 5
    int p5_x;
    int p5_z1;
    int p5_z2;
    int p5_y;

    // Plant 6
    int p6_x;
    int p6_z1;
    int p6_z2;
    int p6_y;

    // Plant 7
    int p7_x;
    int p7_z1;
    int p7_z2;
    int p7_y;

    // Plant 8
    int p8_x;
    int p8_z1;
    int p8_z2;
    int p8_y;

    // Plant 9
    int p9_x;
    int p9_z1;
    int p9_z2;
    int p9_y;

    // Plant 10
    int p10_x;
    int p10_z1;
    int p10_z2;
    int p10_y;

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

    void set_enable_pins();
    void add_stepper_motors();
    void receive_coords(int step_x, int step_y, int step_z1, int step_z2);
    void capture_all_plants();
    bool check_coords(); // returns true and sends message to serial if the coords matches with the received coords
    void debug_mode();
};