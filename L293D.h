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

/* L293D.h */

#ifndef L293D_h
#define L293D_h

#include "Arduino.h"

class L293D {
	public:
		/* object initializer */
		/* ::MOTOR 1::
		 * enable1	: PWM output (speed)
		 * in1		: digital output (direction)
		 * in2		: digital output (direction)
		 
		 * ::MOTOR 2::
		 * enable2	: PWM output (speed)
		 * in3		: digital output (direction)
		 * in4		: digital output (direction)
		 */
		L293D(unsigned int enable1, unsigned int in1, unsigned int in2,
			unsigned int enable2, unsigned int in3, unsigned int in4);
		
		/* object destroyer */
		~L293D();
			
		/* setters
		 * speed	: a range from 0 - 255
		 * direction	: 	REV	|	NEUT	|	FWD
		 *			-1	|	 0	|	 1
		 */
		void 		setM1(unsigned int speed, int direction);		//speed: 0 - 255 | direction REV, NEUT, FWD -1, 0, 1
		void 		setM2(unsigned int speed, int direction);
		
		void		fwd(unsigned int speed);
		void		rev(unsigned int speed);
		void		stop();
		
		/* getters */
		unsigned int 	getM1Speed();
		unsigned int	getM2Speed();
		int		getM1Direction();
		int		getM2Direction();
		
		
	private:
		unsigned int 	_enable1, _enable2, _in1, _in2, _in3, _in4;					//pin numbers		
		unsigned int	_m1Speed, _m2Speed, _m1Direction, _m2Direction;					//flags
		
		
};

#endif
