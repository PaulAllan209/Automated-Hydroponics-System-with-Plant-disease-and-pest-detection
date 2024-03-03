#pragma once

class StepMotor{
    public:
    int step_x;
    int step_y;
    int step_z1;
    int step_z2;

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


    void receive_coords(int step_x, int step_y, int step_z1, int step_z2);
    void move_step_motors();
    bool check_coords(); // returns true and sends message to serial if the coords matches with the received coords
};