/*
  This example reads the analog values from the joystick and
  converts them to a different range. The data comes from the
  analog pins from 0 to 1023. For controlling a motor you may
  wish to convert that to say -255 to 255.

  The data is returned in a struct that contains three values:
  struct {
    joyX: converted value from the x axis
    joyY: converted value from the y axis
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
	// read the joystic data and covert
  joy = joystick.read();

	// print the data to the console
  Serial.print("X:");
  Serial.print(joy.joyX);
  Serial.print(" Y:");
  Serial.print(joy.joyY);
  Serial.print(" B:");
  Serial.println(joy.joyButton);
  
  delay(100);
}