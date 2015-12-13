#include "lightManager.h"

LightManager::LightManager(uint16_t lightCount, uint8_t lightPin)
	: _lightCount(lightCount),
	_neoPixel(lightCount, lightPin, kNeoPixelType)
{
	_aLightArray = new NeoPixelWrapper[_lightCount];
	for (int i = 0; i < _lightCount; i++) {
		_aLightArray[i] = NeoPixelWrapper(&_neoPixel, i);
	}
	_nextLightIndex = 0;
	_lightSubsystemCapacity = kStartingLightSubsystemCount;
	for (int i = 0; i < _lightSubsystemCapacity; i++) {
		_apLightSubsystems[i] = nullptr;
	}
	_nextLightSubsystem = 0;
}

LightManager::~LightManager() {
	delete[] _aLightArray;
}

void LightManager::init() {
	_neoPixel.begin();
	_neoPixel.show();
}

void LightManager::update(float deltaTime)
{
	for (int i = 0; i < _nextLightSubsystem; i++) {
		_apLightSubsystems[i]->update(deltaTime);
	}
	_neoPixel.show();
}

void LightManager::addLightSubsystem(ILightSubsystem& lightSubsystem, uint16_t lightCount) {
	if (_nextLightIndex >= _lightCount) {
		return;
	}
	if (_nextLightSubsystem == _lightSubsystemCapacity) {
		Serial.println("Failed to add, out of subsystems!");
		return;
	}
	_apLightSubsystems[_nextLightSubsystem++] = &lightSubsystem;
	NeoPixelWrapper* pStartPixel = _aLightArray + _nextLightIndex;
	uint16_t endIndex = min(_nextLightIndex + lightCount, _lightCount);
	NeoPixelWrapper* pEndPixel = _aLightArray + endIndex;
	_nextLightIndex = endIndex;

	lightSubsystem.init(LightList(pStartPixel, pEndPixel));
}
