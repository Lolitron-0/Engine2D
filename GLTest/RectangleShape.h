#pragma once
#include <GLFW/glfw3.h>
#include "Vector2.hpp"
#include "Utils.hpp"
#include "Drawable.h"
#include <iostream>
#include <vector>


class RectangleShape : public Drawable
{
#define POINT_COUNT 4

private:

public:
	RectangleShape(float x, float y, float width, float height);

	void draw(); 

	void setPosition(float x, float y);
	void setPosition(Vector2<float>& pos);

private:
	void recountGlCoords();

	Vector2<float> mPosition;
	Vector2<float> mSize;
	//vertices in gl coords
	std::vector<float> mGlVertices;

	GLfloat thickness;
};

