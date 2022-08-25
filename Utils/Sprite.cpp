#include "Sprite.hpp"
#include "Window.hpp"


Sprite::Sprite(float x, float y, float width, float height, std::string source)
				:Shape(4), mTexture(source), mRect(x,y,width,height)
{
	recountGlCoords();
}

void Sprite::draw()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, mTexture.getTextureHandle());

	glColor3ub(255, 255, 255);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glVertexPointer(2, GL_FLOAT, 0, mGlVertices.data());
		glTexCoordPointer(2, GL_FLOAT, 0, mTexture.getTexCoordsPointer());
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Sprite::setPosition(const Vector2<float>& pos)
{
	this->mRect.x = pos.x;
	this->mRect.y = pos.y;
	recountGlCoords();
}

void Sprite::recountGlCoords()
{
	mGlVertices[0] = Window::getInstance().screenToGlX(this->mRect.x);
	mGlVertices[1] = Window::getInstance().screenToGlY(this->mRect.y);

	mGlVertices[2] = Window::getInstance().screenToGlX(this->mRect.x + this->mRect.width);
	mGlVertices[3] = Window::getInstance().screenToGlY(this->mRect.y);

	mGlVertices[4] = Window::getInstance().screenToGlX(this->mRect.x + this->mRect.width);
	mGlVertices[5] = Window::getInstance().screenToGlY(this->mRect.y + this->mRect.height);

	mGlVertices[6] = Window::getInstance().screenToGlX(this->mRect.x);
	mGlVertices[7] = Window::getInstance().screenToGlY(this->mRect.y+this->mRect.height);	
}
