#include "twoColorOscillatingLightHandler.h"

TwoColorOscillatingLightHandler::TwoColorOscillatingLightHandler(
	const Color & color0,
	const Color & color1,
	float period) :
	_color0(color0),
	_color1(color1),
	_period(period),
	_lightList(),
	_time(0.f)
{
}

void TwoColorOscillatingLightHandler::init(const LightList& lightList) {
	_lightList = lightList;
}

void TwoColorOscillatingLightHandler::update(float deltaTime) {
	_time += deltaTime;
	while (_time > _period) {
		_time -= _period;
	}
	_lightList.forEachIndexed(*this);
}

void TwoColorOscillatingLightHandler::operator()(NeoPixelWrapper* pPixelWrapper, uint16_t index) {
	uint16_t pixelCount = _lightList.getCount();
	float pixelPosition = float(index) / float(pixelCount + 1);
	float phase = pixelPosition * 2.f * M_PI;
	float progress = _time / _period;
	float oscillation = cosf(phase + 2.f * M_PI * progress);
	oscillation += 1.f;
	oscillation *= .5f;
	Color color = _color0 * (1.f - oscillation) + _color1 * oscillation;
	pPixelWrapper->setColor(color);
}
