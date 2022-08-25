#include "PrimitiveShape.hpp"
#include <GLFW/glfw3.h>


PrimitiveShape::PrimitiveShape(const Color& color, int pointCount)
	:Shape(pointCount), mColor(color)
{}

void PrimitiveShape::setColor(const Color & color)
{
	mColor = color;
}

Color PrimitiveShape::getColor()
{
	return mColor;
}

void PrimitiveShape::draw()
{
	glVertexPointer(2, GL_FLOAT, 0, mGlVertices.data());
	glEnableClientState(GL_VERTEX_ARRAY);
		glColor3ub(mColor.getR(), mColor.getG(), mColor.getB());
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}
