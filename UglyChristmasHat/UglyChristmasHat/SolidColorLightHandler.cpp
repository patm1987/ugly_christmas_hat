#include "SolidColorLightHandler.h"

SolidColorLightHandler::SolidColorLightHandler(Color desiredColor) :
	_desiredColor(desiredColor),
	_lightList()
{
}

void SolidColorLightHandler::init(const LightList & lightList)
{
	_lightList = lightList;
}

void SolidColorLightHandler::update(float deltaTime)
{
	_lightList.forEach(*this);
}

void SolidColorLightHandler::operator()(NeoPixelWrapper * pPixelManager)
{
	pPixelManager->setColor(_desiredColor);
}
