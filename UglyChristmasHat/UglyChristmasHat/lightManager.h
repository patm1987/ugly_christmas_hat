#pragma once

#include <Adafruit_NeoPixel.h>

#include "color.h"
#include "lightList.h"

class LightManager {
public:
	static const neoPixelType kNeoPixelType = NEO_GRB + NEO_KHZ800;
	static const size_t kStartingLightSubsystemCount = 8;

	class ILightSubsystem {
	public:
		virtual void init(const LightList& lightList) = 0;
		virtual void update(float deltaTime) = 0;
	};

public:
	LightManager(uint16_t lightCount, uint8_t lightPin);
	~LightManager();

	void init();
	void update(float deltaTime);

	void addLightSubsystem(ILightSubsystem& lightSubsystem, uint16_t lightCount);

private:
	uint16_t _lightCount;
	NeoPixelWrapper* _aLightArray;
	uint16_t _nextLightIndex;
	Adafruit_NeoPixel _neoPixel;
	ILightSubsystem* _apLightSubsystems[kStartingLightSubsystemCount];
	size_t _lightSubsystemCapacity;
	int _nextLightSubsystem;
};
