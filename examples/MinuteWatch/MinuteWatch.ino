/*
ShiftDisplay2 example
by Ameer Dawood
Count minutes passing by
https://ameer.io/ShiftDisplay2/
*/

#include <ShiftDisplay2.h>

// Arduino pin 6 connected to shift register latch, pin 7 to clock and pin 5 to data
// common anode display with 2 digits
ShiftDisplay2 display(6, 7, 5, COMMON_ANODE, 2);

void setup() {}

void loop() {
	static int m = 0;
	display.set(m, ALIGN_LEFT);
	for (int i = 0; i < 60; i++) {
		int pos = m < 10 ? 0 : 1;
		display.changeDot(pos);
		display.show(500);
		display.changeDot(pos, false);
		display.show(500);
	}
	m++;
}
