/*
  CW_Joystick.h - Library for reading a 2 axis joystick.
  Created by Chris Ward, Dec, 2016.
  MIT License. See included License file.
*/

#include "Arduino.h"
#include "CW_Joystick.h"

CW_Joystick::CW_Joystick(int xPin, int yPin, int buttonPin)
{
  _xPin = xPin;
	_yPin = yPin;
	_buttonPin = buttonPin;
	pinMode(buttonPin, INPUT_PULLUP);
}

JoyValue CW_Joystick::readRaw()
{
  JoyValue joystick;
	joystick.joyX = analogRead(_xPin);
	joystick.joyY = analogRead(_yPin);
	joystick.joyButton = !digitalRead(_buttonPin);
	return joystick;
}

JoyValue CW_Joystick::read()
{
  JoyValue joystick;
	joystick.joyX = convert(analogRead(_xPin));
	joystick.joyY = convert(analogRead(_yPin));
	joystick.joyButton = !digitalRead(_buttonPin);
	return joystick;
}

int CW_Joystick::convert(int value)
{
  int joy = map(value, 0, 1023, -255, 255);
  if( abs(joy) < 5 ) {
    joy = 0;
  }
  return joy;  
}
