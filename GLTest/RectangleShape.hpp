#pragma once
#include <GLFW/glfw3.h>
#include "Vector2.hpp"
#include "Utils.hpp"
#include <iostream>
#include <vector>
#include "PrimitiveShape.hpp"


class RectangleShape : public PrimitiveShape
{
private:

public:
	RectangleShape(float x, float y, float width, float height);


	void setPosition(float x, float y);
	void setPosition(const Vector2<float>& pos);

private:
	void recountGlCoords();

	Rect<float> mBounds;

};

