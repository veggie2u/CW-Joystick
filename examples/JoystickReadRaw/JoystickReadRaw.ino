/*
  This example reads the raw analog values from the joystick.

  The data is returned in a struct that contains three values:
  struct {
    joyX: analog value from the x axis
    joyY: analog value from the y axis
    joyButton: 0/1 whether button is pressed
	}
*/
#include <CW_Joystick.h>

// These are the pins to read from 
#define XAXIS A1   // an analog pin
#define YAXIS A2   // an analog pin
#define BUTTON A3  // can be a digital pin

// initialize the library
CW_Joystick joystick = CW_Joystick(XAXIS, YAXIS, BUTTON);

// Variable to hold the joystick data
JoyValue joy;

void setup() {
	// the joystick values will get ouput to the console
  Serial.begin(9600);
  Serial.println("Joystick tester.");
}

void loop() {
	// read the raw data
  joy = joystick.readRaw();

	// print the data to the console
  Serial.print("X:");
  Serial.print(joy.joyX);
  Serial.print(" Y:");
  Serial.print(joy.joyY);
  Serial.print(" B:");
  Serial.println(joy.joyButton);
  
  delay(100);
}