#include "Cactus.hpp"

Cactus::Cactus(int x, int y) : GameObject(x,y), Collidable(this, {0,0, 100,100},false ,0,"cactus"), PhysicBody(this, 30),
    mShape(mPosition.x, mPosition.y, 100, 100, "Resources/cactus.jpg")
{
	//this->mShape.setColor(Colors::green);
}

void Cactus::draw()
{
	mShape.draw();
}

void Cactus::update()
{
	mShape.setPosition(mPosition);
	mVelocity.x = -70;
}

void Cactus::resolve(Collidable& other)
{
}
