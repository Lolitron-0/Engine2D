#include "RectangleShape.hpp"


RectangleShape::RectangleShape(float x, float y, float width, float height)
	:Drawable({ 255,0,0 }) ,mGlVertices(POINT_COUNT * 2, 0.f), mPosition(x, y), mSize(width, height)
{
	recountGlCoords();
}

void RectangleShape::draw()
{
	glVertexPointer(2, GL_FLOAT, 0, mGlVertices.data());
	glEnableClientState(GL_VERTEX_ARRAY);
		glColor3f(mColor.getR(), mColor.getG(), mColor.getB());
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void RectangleShape::setPosition(float x, float y)
{
	this->mPosition.x = x;
	this->mPosition.y = y;
	recountGlCoords();
}

void RectangleShape::setPosition(Vector2<float>& pos)
{
	this->mPosition = pos;
	recountGlCoords();
}

void RectangleShape::recountGlCoords()
{
	mGlVertices[0] = screenToGlX(this->mPosition.x);
	mGlVertices[1] = screenToGlY(this->mPosition.y);

	mGlVertices[2] = screenToGlX(this->mPosition.x+this->mSize.x);
	mGlVertices[3] = screenToGlY(this->mPosition.y);

	mGlVertices[4] = screenToGlX(this->mPosition.x+this->mSize.x);
	mGlVertices[5] = screenToGlY(this->mPosition.y+this->mSize.y);

	mGlVertices[6] = screenToGlX(this->mPosition.x);
	mGlVertices[7] = screenToGlY(this->mPosition.y+this->mSize.y);
}
