#include "Dino.hpp"

Dino::Dino(float x, float y)
	:GameObject(x,y), PhysicBody(this, 10), Collidable(this,Rect<float>(0,0, 100,200),false,0,"dino"), KeyListener(),
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
	if (other.getName() == "floor")
		this->mOnGround = true;
	//else if (other.getName() == "cactus")
	//	std::cout << "game over \n";
}

void Dino::onKeyDown(const KeyEventArgs& args)
{
	switch (args.key)
	{
	case GLFW_KEY_SPACE:
		if (mOnGround) 
		{
			mVelocity.y = -60;
			mOnGround = false;
		}
		break;
	default:
		break;
	}
}

void Dino::onKeyUp(const KeyEventArgs& args)
{
}

void Dino::draw()
{
	this->mRect.draw();
}
