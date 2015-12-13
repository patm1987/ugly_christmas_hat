/*
 Name:		UglyChristmasHat.ino
 Created:	12/12/2015 8:58:59 PM
 Author:	pux19
*/
#include <Adafruit_NeoPixel.h>

#include "lightManager.h"
#include "SolidColorLightHandler.h"
#include "twoColorOscillatingLightHandler.h"

#define LIGHT_COUNT 15
#define LIGHT_PIN 6

static LightManager s_lightManager = LightManager(LIGHT_COUNT, LIGHT_PIN);
static uint64_t s_lastTime = 0;

SolidColorLightHandler red(Color(1.f, 0.f, 0.f));
SolidColorLightHandler green(Color(0.f, 1.f, 0.f));
SolidColorLightHandler blue(Color(0.f, 0.f, 1.f));
TwoColorOscillatingLightHandler christmasOscillator(
	Color(1.f, 0.f, 0.f),
	Color(0.f, 1.f, 0.f),
	1.f);

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);

	s_lastTime = millis();

	s_lightManager.addLightSubsystem(red, 1);
	s_lightManager.addLightSubsystem(green, 3);
	s_lightManager.addLightSubsystem(blue, 1);
	s_lightManager.addLightSubsystem(christmasOscillator, 10);

	s_lightManager.init();
}

// the loop function runs over and over again until power down or reset
void loop() {
	uint64_t currentTime = millis();
	float deltaTime = (float)((double)(currentTime - s_lastTime) * 0.001);
	s_lastTime = currentTime;
	s_lightManager.update(deltaTime);
}
