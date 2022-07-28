#include "Dino.hpp"

Dino::Dino(int x, int y)
	:GameObject(x,y), Collidable(Rect<float>(),new Vector2<float>()), mRect(x, y, 100, 200)
{
	this->mRect.setColor(Colors::green);
}

void Dino::update()
{
	mVelosity.x += GRAVITY;


	mPosition.y += mVelosity.x;
	mRect.setPosition(mPosition);
}

void Dino::draw()
{
	this->mRect.draw();
}
