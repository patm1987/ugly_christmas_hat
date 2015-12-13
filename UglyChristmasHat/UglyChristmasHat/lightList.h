#pragma once

#include "neoPixelWrapper.h"

class LightList {
public:
	LightList(NeoPixelWrapper* pStartPixel, NeoPixelWrapper* pEndPixel);
	LightList(const LightList& original);
	LightList();

	template<typename Func>
	void forEach(Func func);

	template<typename Func>
	void forEachIndexed(Func func);

	size_t getCount() const;

private:
	NeoPixelWrapper* _pStartPixel;
	NeoPixelWrapper* _pEndPixel;
};

inline LightList::LightList(NeoPixelWrapper* pStartPixel, NeoPixelWrapper* pEndPixel) :
	_pStartPixel(pStartPixel), _pEndPixel(pEndPixel)
{
}

inline LightList::LightList(const LightList & original) :
	_pStartPixel(original._pStartPixel), _pEndPixel(original._pEndPixel)
{
}

inline LightList::LightList() :
	_pStartPixel(nullptr),
	_pEndPixel(nullptr)
{
}

template<typename Func>
void LightList::forEach(Func func) {
	for (
		NeoPixelWrapper* pIterator = _pStartPixel;
		pIterator != _pEndPixel;
		pIterator++) {

		func(pIterator);
	}
}

template<typename Func>
void LightList::forEachIndexed(Func func) {
	uint16_t index = 0;
	for (
		NeoPixelWrapper* pIterator = _pStartPixel;
		pIterator != _pEndPixel;
		pIterator++, index++) {

		func(pIterator, index);
	}
}

inline size_t LightList::getCount() const {
	return _pEndPixel - _pStartPixel;
}
