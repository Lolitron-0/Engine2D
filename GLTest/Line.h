#pragma once
#include <GLFW/glfw3.h>
#include "Vector2.hpp"
#include "Utils.hpp"
#include "Drawable.h"
#include <vector>
#include <tuple>

class Line : public Drawable
{
public:
	Line(Vector2<GLfloat> start, Vector2<GLfloat> end);
	Line(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);

	void draw() override;

private:

	std::vector<GLfloat> mGlVertices;
	GLfloat mThickness;
};

