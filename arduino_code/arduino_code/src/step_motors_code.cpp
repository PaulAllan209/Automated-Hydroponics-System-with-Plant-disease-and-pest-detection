// #include <Arduino.h>

// // Communication communication;
// // String received_dat;
// // int CTS_pin{13};

// // Millis variables for delaying

// AccelStepper zaxis1(1, 2, 3);
// AccelStepper zaxis2(1, 4, 5);


// // Button Pins
// int button1{8};
// int button2{9};


// void setup() {
//   // communication.def_CTS_pin(CTS_pin);
//   // communication.serial_begin();
//  zaxis1.setMaxSpeed(1000);
//  zaxis1.setSpeed(1000);

//  zaxis2.setMaxSpeed(1000);
//  zaxis2.setSpeed(1000);

//   pinMode(button1, INPUT);
//   pinMode(button2, INPUT);
// }

// void loop() {
//   // while (Serial.available() > 0){
//   //   communication.read_data();
//   //   communication.parse_data();
//   //   if (communication.is_recv){
//   //     communication.print_data();
//   //   }
//   // }


//   if (digitalRead(button1)==HIGH){
//    zaxis1.setSpeed(1000);
//    zaxis1.runSpeed();

//    zaxis2.setSpeed(1000);
//    zaxis2.runSpeed();
//   }

//   if (digitalRead(button2)==HIGH){
//    zaxis1.setSpeed(-1000);
//    zaxis1.runSpeed();

//    zaxis2.setSpeed(-1000);
//    zaxis2.runSpeed();
//   }

// void setup(){
//     Serial.begin(9600);
//     pinMode(LED_BUILTIN, OUTPUT);
//     pinMode(8, INPUT);
//     digitalWrite(LED_BUILTIN, HIGH);

// }

// void loop(){
//     while (Serial.available() > 0){
//         if (Serial.read() == 's'){
//             digitalWrite(2, LOW);
//         }
//     }
//     if (digitalRead(8) == HIGH){
//         Serial.write(p_num);
        
//         p_num+=1;
//     }
// }