#include "neoPixelWrapper.h"

NeoPixelWrapper::NeoPixelWrapper(): _pNeoPixel(nullptr), _lightIndex(-1) {
}

NeoPixelWrapper::NeoPixelWrapper(Adafruit_NeoPixel *pNeoPixel, uint16_t lightIndex) :
	_pNeoPixel(pNeoPixel), _lightIndex(lightIndex)
{
}

NeoPixelWrapper::NeoPixelWrapper(const NeoPixelWrapper& other):
	_pNeoPixel(other._pNeoPixel), _lightIndex(other._lightIndex)
{}

void NeoPixelWrapper::setColor(const Color & color)
{
	if (!_pNeoPixel) {
		Serial.println("_pNeoPixel is null");
		return;
	}
	_pNeoPixel->setPixelColor(_lightIndex, color.toColor(*_pNeoPixel));
}
