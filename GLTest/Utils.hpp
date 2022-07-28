#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <Vector2.hpp>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 500




template <class T>
class Rect
{
public:

	Rect()
		:left(0), top(0), width(0), height(0)
	{}

	Rect(T x, T y, T w, T h)
		:left(x), top(y), width(w), height(h)
	{}

	template <class T>
	bool intersects(const Rect<T>& other, Rect<T>& intersection = Rect<T>()) {
		T intL = std::max(left, other.left);
		T intR = std::min(left + width, other.left + other.width);
		T intT = std::max(top, other.top);
		T intB = std::min(top + height, other.top + other.height);

		if (intR - intL > 0 && intB - intT > 0) {
			intersection = Rect<T>(
				intL,
				intT,
				intR - intL,
				intB - intT
				);
			return true;
		}
		else {
			intersection = Rect<T>();
			return false;
		}

	}

	template<class T> bool contains(Vector2<T> point) {
		return point.x >= left &&
			point.x <= left + width &&
			point.y >= top &&
			point.y <= top + height;
	}

	T top;
	T left;
	T width;
	T height;
};



//convert screen coords to gl coords (0..1)
template<class T> inline Vector2<T> screenToGl(Vector2<T>const& p) {
	return Vector2<T>(p.x / SCREEN_WIDTH, p.y / SCREEN_HEIGHT);
}
//convert screen x to gl x (0..1)
inline float screenToGlX(float v) {
	return v / SCREEN_WIDTH;
}
//convert screen y to gl y (0..1)
inline float screenToGlY(float v) {
	return v / SCREEN_HEIGHT;
}

#endif