#include <Arduino.h>

int length_dat{50};
char received_dat[50];
String received_dat2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0){
    received_dat2 = Serial.readStringUntil(',');
    Serial.println(received_dat2);
  }
}
