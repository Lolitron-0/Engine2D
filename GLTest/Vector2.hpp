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

	Vector2<T> withX(T x)
	{
		return Vector2<T>(x, this->y);
	}
	Vector2<T> withY(T y)
	{
		return Vector2<T>(this->x, y);
	}
	Vector2<T> withXAdded(T val)
	{
		return Vector2<T>(x+val, y);
	}
	Vector2<T> withYAdded(T val)
	{
		return Vector2<T>(x, y+val);
	}

	Vector2<T>& operator=(const Vector2<T>& other)
	{
		Vector2 tmp(other);
		std::swap(tmp.x, this->x);
		std::swap(tmp.y, this->y);
		return *this;
	}


	Vector2<T>& operator=(Vector2<T>&& other)
	{
		std::swap(other.x, this->x);
		std::swap(other.y, this->y);
		return *this;
	}

	T x;
	T y;
};

template <class T>
Vector2<T> operator+(const Vector2<T>& v1, const Vector2<T>& v2)
{
	return Vector2<T>(v1.x + v2.x, v1.y + v2.y);
}
template <class T>
Vector2<T> operator+(const Vector2<T>& v, T val)
{
	return Vector2<T>(v.x + val, v.y + val);
}

template <class T>
Vector2<T> operator-(const Vector2<T>& v1, const Vector2<T>& v2)
{
	return Vector2<T>(v1.x - v2.x, v1.y - v2.y);
}
template <class T>
Vector2<T> operator-(const Vector2<T>& v, T val)
{
	return Vector2<T>(v.x - val, v.y - val);
}
template <class T>
Vector2<T> operator-(T val, const Vector2<T>& v)
{
	return Vector2<T>(val-v.x, val-v.y);
}

template <class T>
Vector2<T> operator*(const Vector2<T>& v1, const Vector2<T>& v2)
{
	return Vector2<T>(v1.x * v2.x, v1.y * v2.y);
}
template <class T>
Vector2<T> operator*(const Vector2<T>& v, T val)
{
	return Vector2<T>(v.x * val, v.y * val);
}

template <class T>
bool operator==(const Vector2<T>& v1, const Vector2<T>& v2)
{
	return v1.x==v2.x && v1.y==v2.y;
}
