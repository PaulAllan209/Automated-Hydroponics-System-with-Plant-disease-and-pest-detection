#include <Arduino.h>

void setup(void)
{
  Serial.begin(9600);
}

void loop(void)
{ 
  Serial.println("wow");
  delay(500);
}