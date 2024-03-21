#include "./modules/step_motor.h"

void StepMotor::receive_coords(int step_x, int step_y, int step_z1, int step_z2){
    recv_step_x = step_x;
    recv_step_y = step_y;
    recv_step_z1 = step_z1;
    recv_step_z2 = step_z2;
}

void StepMotor::move_step_motors(){
}

void StepMotor::send_coords(){
}
