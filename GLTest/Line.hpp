#pragma once
#include <GLFW/glfw3.h>
#include "Vector2.hpp"
#include "Utils.hpp"
#include <vector>
#include <PrimitiveShape.hpp>
#include <tuple>

class Line : public PrimitiveShape
{
public:
	Line(Vector2<GLfloat> start, Vector2<GLfloat> end);
	Line(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);

private:

	GLfloat mThickness;
};

