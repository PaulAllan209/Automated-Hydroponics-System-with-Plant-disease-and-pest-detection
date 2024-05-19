#include "./modules/step_motor.h"

// StepMotor::StepMotor(Communication& comm1_input) : comm1(comm1_input){
// }

void StepMotor::set_enable_pins(){
    step_x.setEnablePin(enable_pin);
    step_z1.setEnablePin(enable_pin);
    step_z2.setEnablePin(enable_pin);
    step_y.setEnablePin(enable_pin);
}

void StepMotor::add_stepper_motors(){
    // Order of adding stepper motor
    // x
    // z1
    // z2
    // y
    stepper_motors.addStepper(step_x);
    stepper_motors.addStepper(step_z1);
    stepper_motors.addStepper(step_z2);
    stepper_motors.addStepper(step_y);

}



void StepMotor::receive_coords(int step_x, int step_y, int step_z1, int step_z2){
    recv_step_x = step_x;
    recv_step_y = step_y;
    recv_step_z1 = step_z1;
    recv_step_z2 = step_z2;
}


void StepMotor::debug_mode(){
    // gantry_debug_state = comm1_input.step_motors.debug_state;
    step_x.setMaxSpeed(250);
    step_z1.setMaxSpeed(8000);
    step_z2.setMaxSpeed(8000);
    step_y.setMaxSpeed(250);

    if (gantry_debug_state==true){
        if (Serial.available() > 0){
            dir_key = Serial.read();
            Serial.print("Step x pos: ");
            Serial.println(step_x.currentPosition());

            Serial.print("Step z1 pos: ");
            Serial.println(step_z1.currentPosition());
            Serial.print("Step z2 pos: ");
            Serial.println(step_z2.currentPosition());

            Serial.print("Step y pos: ");
            Serial.println(step_y.currentPosition());
        }

        if (dir_key == 'w'){
                step_x.setSpeed(250);
                step_x.runSpeed();
        }
        else if (dir_key == 's'){
            step_x.setSpeed(-250);
            step_x.runSpeed(); 
        }

        else if (dir_key == 'a'){
            step_y.setSpeed(250);
            step_y.runSpeed(); 
        }
        else if (dir_key == 'd'){
            step_y.setSpeed(-250);
            step_y.runSpeed(); 
        }
        else if (dir_key == 't'){
            step_z1.setSpeed(8000);
            step_z1.runSpeed();
            step_z2.setSpeed(8000);
            step_z2.runSpeed(); 
        }
        else if (dir_key == 'g'){
            step_z1.setSpeed(-8000);
            step_z1.runSpeed();
            step_z2.setSpeed(-8000);
            step_z2.runSpeed();  
        }

        // test positions for plants
        else if (dir_key == '2'){
            step_x.setSpeed(250);
            step_x.moveTo(p2_x);
            step_x.runSpeedToPosition();

            step_z1.setSpeed(8000);
            step_z1.moveTo(p2_z1);
            step_z1.runSpeedToPosition();

            step_z2.setSpeed(8000);
            step_z2.moveTo(p2_z2);
            step_z2.runSpeedToPosition();

            step_y.setSpeed(250);
            step_y.moveTo(p2_y);
            step_y.runSpeedToPosition();
        }
    }
}
