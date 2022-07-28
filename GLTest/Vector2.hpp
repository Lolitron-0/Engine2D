#pragma once
#include <iostream>

template<class T> class Vector2
{
public:
	Vector2()
		:x(0), y(0)
	{}

	Vector2(T x, T y)
		:x(x), y(y)
	{}

	Vector2(const Vector2<T>&) = default;

	template <class T>
	Vector2<T>& operator=(const Vector2<T>& other)
	{
		Vector2 tmp(other);
		std::swap(tmp.x, this->x);
		std::swap(tmp.y, this->y);
		return *this;
	}


	template <class T>
	Vector2<T>& operator=(Vector2<T>&& other)
	{
		std::swap(other.x, this->x);
		std::swap(other.y, this->y);
		return *this;
	}

	template <class T>
	Vector2<T>& operator+(const Vector2<T>& other)
	{
		return Vector2<T>(this->x + other.x, this->y + other.y);
	}
	
	template <class T>
	Vector2<T>& operator-(const Vector2<T>& other)
	{
		return Vector2<T>(this->x - other.x, this->y - other.y);
	}

	T x;
	T y;
};

