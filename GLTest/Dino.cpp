#include "Dino.hpp"

Dino::Dino(float x, float y)
	:GameObject(x,y), PhysicBody(this, 0.08), Collidable(this,Rect<float>(0,0, 100,200)), 
	mRect(x, y, 100, 200)
{
	this->mRect.setColor(Colors::green);
}

void Dino::update()
{
	mRect.setPosition(mPosition);
}

void Dino::resolve(Collidable& other)
{
}

void Dino::draw()
{
	this->mRect.draw();
}
