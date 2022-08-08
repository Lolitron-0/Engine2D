#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <Vector2.hpp>
#include <algorithm>
#include <cassert>


#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 500




template <typename T>
class Rect
{
public:

	Rect()
		:left(0), top(0), width(0), height(0)
	{}

	Rect(T x, T y, T w, T h)
		:left(x), top(y), width(w), height(h)
	{}

	template <typename U>
	explicit Rect(const Rect<U>& other) :
		left(static_cast<T> (other.left)),
		top(static_cast<T> (other.top)),
		width(static_cast<T> (other.width)),
		height(static_cast<T> (other.height))
	{}

	void setPosition(const Vector2<T>& position)
	{
		this->left = position.x;
		this->top = position.y;
	}
	void setPosition(T x, T y)
	{
		this->left = x;
		this->top = y;
	}

	bool intersects(const Rect<T>& other) const
	{
		T intL = std::max(left, other.left);
		T intR = std::min(left + width, other.left + other.width);
		T intT = std::max(top, other.top);
		T intB = std::min(top + height, other.top + other.height);
		return intR - intL > 0 && intB - intT > 0;
	}

	bool intersects(const Rect<T>& other, Rect<T>& intersection) const
	{
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

	bool contains(Vector2<T> point) const
	{
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

class Math
{
public:
	//returns if point [c] is higher (OR EQUAL) than [a] and lower (OR EQUAL) than [b] or vice versa
	template <typename T>
	static bool isBetween(T a, T b, T c)
	{
		return c >= std::min(a, b) && c <= std::max(a, b);
	}

	//returns if point [c] is higher than [a] and lower than [b] or vice versa
	template <typename T>
	static bool isBetweenStrict(T a, T b, T c)
	{
		return c > std::min(a, b) && c < std::max(a, b);
	}
};

template<typename T>
class Singleton
{
public:
	static T& getInstance()
	{
		if (!Singleton::instance)
			Singleton::instance = createInstance();
		return *(Singleton::instance);
	}
protected:
	inline explicit Singleton() 
	{
		assert(!Singleton::instance);
		Singleton::instance = static_cast<T*>(this);
	}

	inline ~Singleton() 
	{
		Singleton::instance = 0;
	}

private:

	static T* createInstance()  {return new T(); }

	static T* instance;

	inline explicit Singleton(Singleton const&) {}
	inline Singleton& operator=(Singleton const&) { return *this; }
};

template<typename T>
typename T* Singleton<T>::instance = 0;



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