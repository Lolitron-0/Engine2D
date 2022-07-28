#pragma once
#include <tuple>
#include <limits>

template<class Type>
class Color {
public:
	Color(Type r, Type g, Type b, Type a = std::numeric_limits<Type>::max())
		: r(r), g(g), b(b), a(a)
	{}

	Color() = default;

	Type getR() { return r; }
	Type getG() { return g; }
	Type getB() { return b; }
	Type getA() { return a; }

private:
	Type r, g, b, a;
};

namespace Colors {
	static const Color<unsigned __int8> transparent = Color<unsigned __int8>(0, 0, 0, 0);
	static const Color<unsigned __int8> black = Color<unsigned __int8>(0, 0, 0);
	static const Color<unsigned __int8> red = Color<unsigned __int8>(255, 0, 0);
	static const Color<unsigned __int8> green = Color<unsigned __int8>(0, 255, 0);
	static const Color<unsigned __int8> blue = Color<unsigned __int8>(0, 0, 255);
	static const Color<unsigned __int8> white = Color<unsigned __int8>(255, 255, 255);
}
