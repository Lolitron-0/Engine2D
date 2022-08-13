#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <Vector2.hpp>
#include <algorithm>
#include <cassert>
#include <GLFW/glfw3.h>


#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 500




template <typename T>
class Rect
{
public:

	Rect()
		:x(0), y(0), width(0), height(0)
	{}

	Rect(T x, T y, T w, T h)
		:x(x), y(y), width(w), height(h)
	{}

	template <typename U>
	explicit Rect(const Rect<U>& other) :
		x(static_cast<T> (other.x)),
		y(static_cast<T> (other.y)),
		width(static_cast<T> (other.width)),
		height(static_cast<T> (other.height))
	{}

	void setPosition(const Vector2<T>& position)
	{
		this->x = position.x;
		this->y = position.y;
	}
	void setPosition(T x, T y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2<T> getTopLeft() const { return { x,y }; }
	Vector2<T> getBottomLeft() const { return { x,y+height }; }
	Vector2<T> getBottomRight() const { return { x+width,y+height }; }
	Vector2<T> getTopRight() const { return { x+width,y }; }

	bool intersects(const Rect<T>& other) const
	{
		T intL = std::max(x, other.x);
		T intR = std::min(x + width, other.x + other.width);
		T intT = std::max(y, other.y);
		T intB = std::min(y + height, other.y + other.height);
		return intR - intL > 0 && intB - intT > 0;
	}

	bool intersects(const Rect<T>& other, Rect<T>& intersection) const
	{
		T intL = std::max(x, other.x);
		T intR = std::min(x + width, other.x + other.width);
		T intT = std::max(y, other.y);
		T intB = std::min(y + height, other.y + other.height);

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
		return point.x >= x &&
			point.x <= x + width &&
			point.y >= y &&
			point.y <= y + height;
	}

	T y;
	T x;
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

	template <typename T>
	static bool isOnSegment(const Vector2<T>& a, const Vector2<T>& b, const Vector2<float>& point)
	{
		return (point.x - a.x) * (b.y - a.y) - (point.y - a.y) * (b.x - a.x) == 0 &&
			(point.x >= a.x &&
				b.x >= point.x || point.x >= b.x && a.x >= point.x);
	}

	template <typename T>
	static bool length2D(const Vector2<T>& a, const Vector2<T>& b)
	{
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
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

	static T* createInstance()  {return new T(); }
private:
	static T* instance;

	inline explicit Singleton(Singleton const&) {}
	inline Singleton& operator=(Singleton const&) { return *this; }
};

template<typename T>
typename T* Singleton<T>::instance = 0;



#endif