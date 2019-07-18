/*
ShiftDisplay2 example
by Ameer Dawood
Race countdown: 3.. 2.. 1.. GO!
https://ameer.io/ShiftDisplay2/
*/

#include <ShiftDisplay2.h>

ShiftDisplay2 display(COMMON_CATHODE, 3);

void setup() {
	for (int i = 3; i > 0; i--) {
		// store number and show it for 400ms
		display.set(i, ALIGN_CENTER);
		display.show(400);
		// add dot to stored number and show it for 400ms
		display.changeDot(1);
		display.show(400);
	}
	display.set("GO"); // store "GO"
}

void loop() {
	display.update(); // show stored "GO" while in loop
}
