#ifndef _GammaCorrectionLib_h
#define _GammaCorrectionLib_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class GammaCorrection
{
	public:
	
		static uint8_t Correct8(uint8_t value);
		static uint8_t CorrectTable8(uint8_t value);

	private:
		const static uint8_t * PROGMEM Table8;
};

#endif
