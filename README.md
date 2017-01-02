# CW_Joystick
Arduino library to read a 2 axis analog joystick.
  
This library was designed for and tested with this product:
[https://www.adafruit.com/products/512]
It should work with any analog joystick. It also includes support for
a button like the one in the product above.

Created by Chris Ward, Dec, 2016.
MIT License. See included License file.


##Usage
The joystick must be created like this:
CW_Joystick joystick = CW_Joystick(XAXIS, YAXIS, BUTTON);
You just need to pass the pins to iniatialize.

You then read raw data with 
`joystick.readRaw();`

Or read the converted values with
`joystick.read();`
The data is currently mapped from 0 => 1023 to -255 => 255.
For now, change this in the .cpp file. I started making methods to 
change these values, but decided it was overkill for reading a couple
of analog pins.

The data is returned in a struct
```C
struct {
    joyX: converted value from the x axis
    joyY: converted value from the y axis
    joyButton: 0/1 whether button is pressed
}
```
