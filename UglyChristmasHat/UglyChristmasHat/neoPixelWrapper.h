#pragma once

#include <Adafruit_NeoPixel.h>

#include "color.h"

class NeoPixelWrapper {
public:
	NeoPixelWrapper();
	NeoPixelWrapper(Adafruit_NeoPixel *pNeoPixel, uint16_t lightIndex);
	NeoPixelWrapper(const NeoPixelWrapper& other);

	void setColor(const Color& color);
	
private:
	Adafruit_NeoPixel *_pNeoPixel;
	uint16_t _lightIndex;
};
