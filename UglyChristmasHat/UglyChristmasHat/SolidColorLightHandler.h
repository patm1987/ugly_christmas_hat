#pragma once

#include "color.h"
#include "lightManager.h"

class SolidColorLightHandler : public LightManager::ILightSubsystem {
public:
	SolidColorLightHandler(Color desiredColor);

	virtual void init(const LightList& lightList) override;
	virtual void update(float deltaTime) override;

	void operator()(NeoPixelWrapper* pPixelManager);

private:
	Color _desiredColor;
	LightList _lightList;
};
