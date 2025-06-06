/*
step_motor.cpp

This file handles the movement functionality of the gantry robot.
It ensures the proper synchronization and axis movements of the stepper motors.
*/

#include "./modules/step_motor.h"

StepMotor::StepMotor(Communication& comm1_input) : comm1(comm1_input){
}

void StepMotor::set_enable_pins(){
    step_x.setEnablePin(enable_pin);
    step_z1.setEnablePin(enable_pin);
    step_z2.setEnablePin(enable_pin);
    step_y.setEnablePin(enable_pin);
}

void StepMotor::enable_pins_state(){
    if (comm1.step_motors.enable_pins == 1){
        step_x.enableOutputs();
        step_z1.enableOutputs();
        step_z2.enableOutputs();
        step_y.enableOutputs();
    }
    else if (comm1.step_motors.enable_pins == 0){
        step_x.disableOutputs();
        step_z1.disableOutputs();
        step_z2.disableOutputs();
        step_y.disableOutputs();
    }
}

void StepMotor::set_limit_switches_pins(){
    pinMode(x_limit, INPUT_PULLUP);
    pinMode(z_limit, INPUT_PULLUP);
    pinMode(y_limit, INPUT_PULLUP);
}

void StepMotor::set_max_speed(){
    step_x.setMaxSpeed(5000);
    step_z1.setMaxSpeed(12000);
    step_z2.setMaxSpeed(12000);
    step_y.setMaxSpeed(5000);
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

void StepMotor::go_home_pos(){
    step_x.setMaxSpeed(5000);
    step_z1.setMaxSpeed(12000);
    step_z2.setMaxSpeed(12000);
    step_y.setMaxSpeed(5000);

    if(digitalRead(x_limit) == HIGH){
        step_x.setSpeed(5000);
        step_x.runSpeed();
    }

    if(digitalRead(y_limit) == HIGH){
        step_y.setSpeed(-5000);
        step_y.runSpeed();
    }

    if(digitalRead(z_limit) == HIGH){
        step_z1.setSpeed(-12000);
        step_z2.setSpeed(-12000);
        step_z1.runSpeed();
        step_z2.runSpeed();
    }

    if (digitalRead(x_limit) == LOW){
        if(digitalRead(y_limit) == LOW){
            if(digitalRead(z_limit) == LOW){
                step_x.setCurrentPosition(0);
                step_y.setCurrentPosition(0);
                step_z1.setCurrentPosition(0);
                step_z2.setCurrentPosition(0);
                
                return_home_position = true;
                capture_plants_ready = true;
                // Serial1.println("at_home");
            }
        }
    }
}

void StepMotor::capture_plant_debug(){
    step_x.setMaxSpeed(-5000);
    step_z1.setMaxSpeed(12000);
    step_z2.setMaxSpeed(12000);
    step_y.setMaxSpeed(5000);

    step_x.setSpeed(-5000);
    step_z1.setSpeed(12000);
    step_z2.setSpeed(12000);
    step_y.setSpeed(5000);

    if(Serial.available() > 0){
        capture_plants_debug_key = Serial.read();
        if (capture_plants_debug_key == 'r'){
            capture_plants_debug = true;
        }
    }

    if (capture_plants_debug_key == 'r'){
        go_home_pos();
    }

    if (capture_plants_debug_key =='1'){
        step_x.moveTo(p1_x);
        step_z1.moveTo(p1_z1);
        step_z2.moveTo(p1_z1);
        step_y.moveTo(p1_y);

        step_x.runSpeedToPosition();
        step_z1.runSpeedToPosition();
        step_z2.runSpeedToPosition();
        step_y.runSpeedToPosition();
    }

    if (capture_plants_debug_key == '2'){
        step_x.moveTo(p2_x);
        step_z1.moveTo(p2_z1);
        step_z2.moveTo(p2_z1);
        step_y.moveTo(p2_y);

        step_x.runSpeedToPosition();
        step_z1.runSpeedToPosition();
        step_z2.runSpeedToPosition();
        step_y.runSpeedToPosition();
    }

    if (capture_plants_debug_key == '3'){
        step_x.moveTo(p3_x);
        step_z1.moveTo(p3_z1);
        step_z2.moveTo(p3_z1);
        step_y.moveTo(p3_y);

        step_x.runSpeedToPosition();
        step_z1.runSpeedToPosition();
        step_z2.runSpeedToPosition();
        step_y.runSpeedToPosition();
    }

    if (capture_plants_debug_key == '4'){
        step_x.moveTo(p4_x);
        step_z1.moveTo(p4_z1);
        step_z2.moveTo(p4_z1);
        step_y.moveTo(p4_y);

        step_x.runSpeedToPosition();
        step_z1.runSpeedToPosition();
        step_z2.runSpeedToPosition();
        step_y.runSpeedToPosition();
    }

    if (capture_plants_debug_key == '5'){
        step_x.moveTo(p5_x);
        step_z1.moveTo(p5_z1);
        step_z2.moveTo(p5_z1);
        step_y.moveTo(p5_y);

        step_x.runSpeedToPosition();
        step_z1.runSpeedToPosition();
        step_z2.runSpeedToPosition();
        step_y.runSpeedToPosition();
    }

    if (capture_plants_debug_key == '6'){
        step_x.moveTo(p6_x);
        step_z1.moveTo(p6_z1);
        step_z2.moveTo(p6_z1);
        step_y.moveTo(p6_y);

        step_x.runSpeedToPosition();
        step_z1.runSpeedToPosition();
        step_z2.runSpeedToPosition();
        step_y.runSpeedToPosition();
    }

    if (capture_plants_debug_key == '7'){
        step_x.moveTo(p7_x);
        step_z1.moveTo(p7_z1);
        step_z2.moveTo(p7_z1);
        step_y.moveTo(p7_y);

        step_x.runSpeedToPosition();
        step_z1.runSpeedToPosition();
        step_z2.runSpeedToPosition();
        step_y.runSpeedToPosition();
    }

    if (capture_plants_debug_key == '8'){
        step_x.moveTo(p8_x);
        step_z1.moveTo(p8_z1);
        step_z2.moveTo(p8_z1);
        step_y.moveTo(p8_y);

        step_x.runSpeedToPosition();
        step_z1.runSpeedToPosition();
        step_z2.runSpeedToPosition();
        step_y.runSpeedToPosition();
    }

    if (capture_plants_debug_key == '9'){
        step_x.moveTo(p9_x);
        step_z1.moveTo(p9_z1);
        step_z2.moveTo(p9_z1);
        step_y.moveTo(p9_y);

        step_x.runSpeedToPosition();
        step_z1.runSpeedToPosition();
        step_z2.runSpeedToPosition();
        step_y.runSpeedToPosition();
    }

    if (capture_plants_debug_key == '0'){
        step_x.moveTo(p10_x);
        step_z1.moveTo(p10_z1);
        step_z2.moveTo(p10_z1);
        step_y.moveTo(p10_y);

        step_x.runSpeedToPosition();
        step_z1.runSpeedToPosition();
        step_z2.runSpeedToPosition();
        step_y.runSpeedToPosition();
    }
}

void StepMotor::capture_all_plants(){
    step_x.setMaxSpeed(-5000);
    step_z1.setMaxSpeed(12000);
    step_z2.setMaxSpeed(12000);
    step_y.setMaxSpeed(5000);

    step_x.setSpeed(-5000);
    step_z1.setSpeed(12000);
    step_z2.setSpeed(12000);
    step_y.setSpeed(5000);

    if (comm1.step_motors.capture_plants == 1){

        if (comm1.step_motors.return_home_position == 1){
            go_home_pos();
        }
            
        if (comm1.step_motors.next_plant_state == 1){
            step_x.moveTo(p1_x);
            step_z1.moveTo(p1_z1);
            step_z2.moveTo(p1_z1);
            step_y.moveTo(p1_y);

            step_x.runSpeedToPosition();
            step_z1.runSpeedToPosition();
            step_z2.runSpeedToPosition();
            step_y.runSpeedToPosition();
        }

        if (comm1.step_motors.next_plant_state == 2){
            step_x.moveTo(p2_x);
            step_z1.moveTo(p2_z1);
            step_z2.moveTo(p2_z1);
            step_y.moveTo(p2_y);

            step_x.runSpeedToPosition();
            step_z1.runSpeedToPosition();
            step_z2.runSpeedToPosition();
            step_y.runSpeedToPosition();
        }

        if (comm1.step_motors.next_plant_state == 3){
            step_x.moveTo(p3_x);
            step_z1.moveTo(p3_z1);
            step_z2.moveTo(p3_z1);
            step_y.moveTo(p3_y);

            step_x.runSpeedToPosition();
            step_z1.runSpeedToPosition();
            step_z2.runSpeedToPosition();
            step_y.runSpeedToPosition();
        }

        if (comm1.step_motors.next_plant_state == 4){
            step_x.moveTo(p4_x);
            step_z1.moveTo(p4_z1);
            step_z2.moveTo(p4_z1);
            step_y.moveTo(p4_y);

            step_x.runSpeedToPosition();
            step_z1.runSpeedToPosition();
            step_z2.runSpeedToPosition();
            step_y.runSpeedToPosition();
        }

        if (comm1.step_motors.next_plant_state == 5){
            step_x.moveTo(p5_x);
            step_z1.moveTo(p5_z1);
            step_z2.moveTo(p5_z1);
            step_y.moveTo(p5_y);

            step_x.runSpeedToPosition();
            step_z1.runSpeedToPosition();
            step_z2.runSpeedToPosition();
            step_y.runSpeedToPosition();
        }

        if (comm1.step_motors.next_plant_state == 6){
            step_x.moveTo(p6_x);
            step_z1.moveTo(p6_z1);
            step_z2.moveTo(p6_z1);
            step_y.moveTo(p6_y);

            step_x.runSpeedToPosition();
            step_z1.runSpeedToPosition();
            step_z2.runSpeedToPosition();
            step_y.runSpeedToPosition();
        }

        if (comm1.step_motors.next_plant_state == 7){
            step_x.moveTo(p7_x);
            step_z1.moveTo(p7_z1);
            step_z2.moveTo(p7_z1);
            step_y.moveTo(p7_y);

            step_x.runSpeedToPosition();
            step_z1.runSpeedToPosition();
            step_z2.runSpeedToPosition();
            step_y.runSpeedToPosition();
        }

        if (comm1.step_motors.next_plant_state == 8){
            step_x.moveTo(p8_x);
            step_z1.moveTo(p8_z1);
            step_z2.moveTo(p8_z1);
            step_y.moveTo(p8_y);

            step_x.runSpeedToPosition();
            step_z1.runSpeedToPosition();
            step_z2.runSpeedToPosition();
            step_y.runSpeedToPosition();
        }

        if (comm1.step_motors.next_plant_state == 9){
            step_x.moveTo(p9_x);
            step_z1.moveTo(p9_z1);
            step_z2.moveTo(p9_z1);
            step_y.moveTo(p9_y);

            step_x.runSpeedToPosition();
            step_z1.runSpeedToPosition();
            step_z2.runSpeedToPosition();
            step_y.runSpeedToPosition();
        }

        if (comm1.step_motors.next_plant_state == 10){
            step_x.moveTo(p10_x);
            step_z1.moveTo(p10_z1);
            step_z2.moveTo(p10_z1);
            step_y.moveTo(p10_y);

            step_x.runSpeedToPosition();
            step_z1.runSpeedToPosition();
            step_z2.runSpeedToPosition();
            step_y.runSpeedToPosition();
        }
    }
}

void StepMotor::debug_mode(){
    // gantry_debug_state = comm1_input.step_motors.debug_state;
    step_x.setMaxSpeed(5000);
    step_z1.setMaxSpeed(8000);
    step_z2.setMaxSpeed(8000);
    step_y.setMaxSpeed(5000);

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
        }
        if (dir_key == 'w'){
            if (digitalRead(x_limit)==HIGH){
                step_x.setSpeed(5000);
                step_x.runSpeed();
            }
        }
                
        else if (dir_key == 's'){
            step_x.setSpeed(-5000);
            step_x.runSpeed(); 
        }

        else if (dir_key == 'a'){
            step_y.setSpeed(5000);
            step_y.runSpeed(); 
        }
        else if (dir_key == 'd'){
            if (digitalRead(y_limit) == HIGH){
                step_y.setSpeed(-5000);
                step_y.runSpeed(); 
            }
        }

        else if (dir_key == 't'){
            step_z1.setSpeed(8000);
            step_z1.runSpeed();
            step_z2.setSpeed(8000);
            step_z2.runSpeed(); 
        }
        else if (dir_key == 'g'){
            if (digitalRead(z_limit) == HIGH){
                step_z1.setSpeed(-8000);
                step_z1.runSpeed();
                step_z2.setSpeed(-8000);
                step_z2.runSpeed(); 
            }
             
        }
        else if (dir_key == 'p'){
            step_x.enableOutputs();
        }
        else if (dir_key == 'l'){
            step_x.disableOutputs();
        }

        // test go to home pos
        else if (dir_key == 'o'){
            go_home_pos();
            // dir_key = 'k';
        }
}


// StepMotor::StepMotor(Communication& comm1_input) : comm1(comm1_input){
// }
