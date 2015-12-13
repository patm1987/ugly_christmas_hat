#pragma once

#include "lightManager.h"

class TwoColorOscillatingLightHandler : public LightManager::ILightSubsystem {
public:
	TwoColorOscillatingLightHandler(
		const Color& color0,
		const Color& color1,
		float period);
	virtual void init(const LightList& lightList) override;
	virtual void update(float deltaTime) override;

	void operator()(NeoPixelWrapper* pPixelWrapper, uint16_t index);

private:
	Color _color0;
	Color _color1;

	float _period;

	LightList _lightList;

	float _time;
};
