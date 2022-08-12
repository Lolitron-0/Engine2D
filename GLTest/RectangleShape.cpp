#include "RectangleShape.hpp"
#include <Window.hpp>


RectangleShape::RectangleShape(float x, float y, float width, float height)
	:PrimitiveShape(Colors::red,4), mBounds(x,y,width, height)
{
	recountGlCoords();
}

void RectangleShape::setPosition(float x, float y)
{
	this->mBounds.x = x;
	this->mBounds.y = y;
	recountGlCoords();
}

void RectangleShape::setPosition(const Vector2<float>& pos)
{
	this->mBounds.setPosition(pos);
	recountGlCoords();
}

void RectangleShape::recountGlCoords()
{
	mGlVertices[0] = Window::getInstance().screenToGlX(this->mBounds.x);
	mGlVertices[1] = Window::getInstance().screenToGlY(this->mBounds.y);

	mGlVertices[2] = Window::getInstance().screenToGlX(this->mBounds.x + this->mBounds.width);
	mGlVertices[3] = Window::getInstance().screenToGlY(this->mBounds.y);

	mGlVertices[4] = Window::getInstance().screenToGlX(this->mBounds.x + this->mBounds.width);
	mGlVertices[5] = Window::getInstance().screenToGlY(this->mBounds.y + this->mBounds.height);

	mGlVertices[6] = Window::getInstance().screenToGlX(this->mBounds.x);
	mGlVertices[7] = Window::getInstance().screenToGlY(this->mBounds.y+this->mBounds.height);
}

