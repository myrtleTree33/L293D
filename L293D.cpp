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
	@Descr		: This code abstracts connection to the L293D motor driver IC.  Please refer to the datasheet for the L293D to understand how 				  the IC works.
			  
			  To use, extract L293D.cpp and L293D.h in the directory "<PATH-TO-ARDUINO-IDE-LIBRARY>/L293D/".
			  
			  Please refer to the header file for function definitions.

*/

/* L293D.cpp */

#include "Arduino.h"
#include "L293D.h"

L293D::L293D(unsigned int enable1, unsigned int in1, unsigned int in2,
			unsigned int enable2, unsigned int in3, unsigned int in4) {
	_enable1 = enable1;
	_enable2 = enable2;
	_in1 = in1;
	_in2 = in2;
	_in3 = in3;
	_in4 = in4;
	
	pinMode(_in1, OUTPUT);			//initialize pins
	pinMode(_in2, OUTPUT);
	pinMode(_in3, OUTPUT);
	pinMode(_in4, OUTPUT);
	
	setM1(0,0);				//reset all outputs and flags
	setM2(0,0);
	
}

L293D::~L293D() {}

void L293D::setM1(unsigned int speed, int direction) {
	if (direction == 1) {
		digitalWrite(_in1, HIGH);
		digitalWrite(_in2, LOW);
		_m1Direction = 1;
		
	} else if (direction == 0) {
		digitalWrite(_in1, LOW);
		digitalWrite(_in2, LOW);
		_m1Direction = 0;
		
	} else if (direction == -1) {
		digitalWrite(_in1, LOW);
		digitalWrite(_in2, HIGH);
		_m1Direction = -1;
	}
	
	analogWrite(_enable1, speed);
	_m1Speed = speed;
}

void L293D::setM2(unsigned int speed, int direction) {
	if (direction == 1) {
		digitalWrite(_in3, HIGH);
		digitalWrite(_in4, LOW);
		_m2Direction = 1;
		
	} else if (direction == 0) {
		digitalWrite(_in3, LOW);
		digitalWrite(_in4, LOW);
		_m2Direction = 0;
		
	} else if (direction == -1) {
		digitalWrite(_in3, LOW);
		digitalWrite(_in4, HIGH);
		_m2Direction = -1;
	}
	
	analogWrite(_enable2, speed);
	_m2Speed = speed;
}

/* getters */
unsigned int L293D::getM1Speed() { return _m1Speed; }
unsigned int L293D::getM2Speed() { return _m2Speed; }
int L293D::getM1Direction() { return _m1Direction; }
int L293D::getM2Direction() { return _m2Direction; }


/* abstract motor control */
void L293D::fwd(unsigned int speed) {
	setM1(speed, 1);
	setM2(speed, 1);
}

void L293D::rev(unsigned int speed) {
	setM1(speed, -1);
	setM2(speed, -1);
}

void L293D::stop() {
	setM1(0,0);
	setM2(0,0);
}
