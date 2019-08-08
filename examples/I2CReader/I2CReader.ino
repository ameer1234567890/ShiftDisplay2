/*
ShiftDisplay2 example
by Ameer Dawood
Receive pre-formatted data over I2C
https://ameer.io/ShiftDisplay2/
*/

#include <ShiftDisplay2.h>
#include <Wire.h>
// connect pin A4 to other Arduino pin A4, pin A5 to other Arduino pin A5, and GND to other Arduino GND

#ifdef ESP32
bool isEsp32 = true;
#endif

const int DISPLAY_ADDRESS = 8;
const int LATCH_PIN = 6;
const int CLOCK_PIN = 7;
const int DATA_PIN = 5;
const DisplayType DISPLAY_TYPE = COMMON_CATHODE; // COMMON_CATHODE or COMMON_ANODE
const int DISPLAY_SIZE = 4; // number of digits on display

ShiftDisplay2 display(LATCH_PIN, CLOCK_PIN, DATA_PIN, DISPLAY_TYPE, DISPLAY_SIZE);

void receiveEvent(int numBytes) {
	char str[numBytes];
	for (int i = 0; i < numBytes; i++)
		str[i] = Wire.read();
	display.set(str); // store received value
}

void setup() {
	if (isEsp32) {
		display.set("XWRK"); // i2c slave mode does not work in ESP32, yet. Refer: https://github.com/espressif/arduino-esp32/issues/118
	} else {
		Wire.begin(DISPLAY_ADDRESS); // this is slave
		Wire.onReceive(receiveEvent);
	}
}

void loop() {
	display.update(); // show current stored value
}
