#include "Line.h"

Line::Line(Vector2<GLfloat> start, Vector2<GLfloat> end)
	:Drawable({255,255,255})
{
	mGlVertices = { screenToGlX(start.x), screenToGlY(start.y), screenToGlX(end.x), screenToGlY(end.y) };
}

Line::Line(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
	: Drawable({ 1,1,1 })
{
	mGlVertices = { screenToGlX(x1), screenToGlY(y1), screenToGlX(x2), screenToGlY(y2) };
}

void Line::draw()
{
	glVertexPointer(2, GL_FLOAT, 0, this->mGlVertices.data());
	glEnableClientState(GL_VERTEX_ARRAY);
	glColor3f(mColor.getR(),
		mColor.getG(),
		mColor.getB());
	glDrawArrays(GL_LINES, 0, mGlVertices.size());
	glDisableClientState(GL_VERTEX_ARRAY);
}

