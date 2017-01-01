/*
  CW_Joystick.h - Library for reading a 2 axis joystick.
  Created by Chris Ward, Dec, 2016.
  MIT License. See included License file.
*/
#ifndef CW_Joystick_h
#define CW_Joystick_h

#include "Arduino.h"

struct JoyValue {
  int joyX;
  int joyY;
  int joyButton;
};

class CW_Joystick
{
  public:
    CW_Joystick(int xPin, int yPin, int buttonPin);
    JoyValue readRaw();
    JoyValue read();
		
	private:
    int _xPin;
		int _yPin;
		int _buttonPin;
		int convert(int value);
};
#endif
