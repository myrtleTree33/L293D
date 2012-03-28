/*

**   L293D MOTOR CONTROLLER DRIVER   **
**         class for Arduino         **

Copyright (C) 2012 TONG Haowen Joel

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

	@Name		: TONG Haowen Joel
	@Organization	: Singapore Academy for Young Engineers and Scientists (SAYES), Science Centre Singapore
	@Email		: code {at} joeltong {dot} org
	@Language	: Arduino-C
	@Descr		: Example file for L293D class use.

*/

/* L293D class example deployment script */

#include <L293D.h>

void setup() {
	Serial.begin(9600);				//so we can echo getter values to screen
}

void loop() {
	L293D l293d(5,6,7,10,9,8);			//initializer
	
	l293d.fwd(255);					//full speed forward for 1000ms
	delay(1000);
	
	l293d.rev(128);					//half speed reverse for 1000ms
	delay(1000);
	
	l293d.stop();					//stop for 500ms
	delay(500);
	
	l293d.setM1(255,1);				//set motor 1 to spin at full speed FWD direction for 1000 ms
	l293d.setM2(128,-1);				//set motor 2 to spin at half speed REV direction for 1000 ms
	delay(1000);
	
	Serial.println( l293d.getM1speed() );		//outputs speed of motor 1
	Serial.println( l293d.getM1Direction() );	//outputs direction of motor 1
	delay(2000);
	
	l293d.stop();					//stop for 3000 ms
	delay(3000);
}
