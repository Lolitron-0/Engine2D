#pragma once
#include <tuple>
#include <limits>
#include <cstdint>

class Color {

	typedef uint8_t  uint8;

public:
	Color(uint8 r, uint8 g, uint8 b, uint8 a = std::numeric_limits<uint8>::max())
		: r(r), g(g), b(b), a(a)
	{}

	Color() = default;

	uint8 getR() { return r; }
	uint8 getG() { return g; }
	uint8 getB() { return b; }
	uint8 getA() { return a; }

private:
	uint8 r, g, b, a;
};

namespace Colors {
	static const Color transparent = Color(0, 0, 0, 0);
	static const Color black = Color(0, 0, 0);
	static const Color red = Color(255, 0, 0);
	static const Color green = Color(0, 255, 0);
	static const Color blue = Color(0, 0, 255);
	static const Color white = Color(255, 255, 255);
}
