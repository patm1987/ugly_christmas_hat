#pragma once

#include <Adafruit_NeoPixel.h>

struct Color {
	inline Color() : r(0.f), g(0.f), b(0.f) {}
	inline Color(float red, float green, float blue) : r(red), g(green), b(blue) {}

	union {
		float c[3];
		struct {
			float r, g, b;
		};
	};

	static inline float clamp(const float& value, const float& min, const float& max) {
		if (value < min) {
			return min;
		}
		if (value > max) {
			return max;
		}
		return value;
	}

	inline static uint8_t floatToColorChannel(float color) {
		return static_cast<uint8_t>(clamp(color * 255.f, 0.f, 255.f));
	}

	inline uint32_t toColor(Adafruit_NeoPixel& neoPixel) const {
		return neoPixel.Color(
			floatToColorChannel(r),
			floatToColorChannel(g),
			floatToColorChannel(b));
	}

	inline Color operator-(const Color& rhs) const {
		Color outColor;
		for (int i = 0; i < 3; i++) {
			outColor.c[i] = c[i] - rhs.c[i];
		}
		return outColor;
	}

	inline Color operator+(const Color& rhs) const {
		Color outColor;
		for (int i = 0; i < 3; i++) {
			outColor.c[i] = c[i] + rhs.c[i];
		}
		return outColor;
	}

	inline Color operator*(const float& scale) {
		Color outColor;
		for (int i = 0; i < 3; i++) {
			outColor.c[i] = c[i] * scale;
		}
		return outColor;
	}
};
