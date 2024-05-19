#pragma once
#include <MultiStepper.h>
#include <AccelStepper.h>

class StepMotor{
    public:
    // Communication& comm1;
    // RegulatedParam(Communication& comm1_input);

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

    // Curr coords
    int curr_step_x;
    int curr_step_y;
    int curr_step_z1;
    int curr_step_z2;

    // Target coords
    int recv_step_x;
    int recv_step_y;
    int recv_step_z1;
    int recv_step_z2;

    // debug mode
    char dir_key;

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
    void send_coords();
    void move_step_motors();
    bool check_coords(); // returns true and sends message to serial if the coords matches with the received coords
    void debug_mode();
};