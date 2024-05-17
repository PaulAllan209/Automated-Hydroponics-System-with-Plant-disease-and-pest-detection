#pragma once
#include <MultiStepper.h>
#include <AccelStepper.h>

class StepMotor{
    public:
    // Pins
    int x_axis_pulse{33};
    int x_axis_dir{34};
    int z1_axis_pulse{35};
    int z1_axis_dir{36};
    int z2_axis_pulse{37};
    int z2_axis_dir{38};
    int y_axis_pulse{39};
    int y_axis_dir{40};
    int enable_pin{41};

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

    bool coords_is_equal = true; // state for checking if the stepper motor coords are equal to the sent by raspberry pi

    // Stepper motor speed parameters
    unsigned long time_counter1;
    unsigned long time_counter2;
    unsigned long step_speed = {10};

    bool gantry_debug_state{false}; // when setting the coordinates for the plants

    // Stepper motor classes
    // (motor interface ,pulse_pin, dir_pin)
    // Motor interface is 1 meaning i have a stepper motor driver
    int motor_interface{1};
    AccelStepper step_x(motor_interface, x_axis_pulse, x_axis_dir);
    AccelStepper step_z1(motor_interface, z1_axis_pulse, z1_axis_dir);
    AccelStepper step_z2(motor_interface, z2_axis_pulse, z2_axis_dir);
    AccelStepper step_y(motor_interface, y_axis_pulse, y_axis_dir);

    MultiStepper stepper_motors;

    void set_enable_pins();
    void add_stepper_motors();
    void receive_coords(int step_x, int step_y, int step_z1, int step_z2);
    void send_coords();
    void move_step_motors();
    bool check_coords(); // returns true and sends message to serial if the coords matches with the received coords
    void debug_mode();
};