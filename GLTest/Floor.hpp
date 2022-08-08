#pragma once
#include <EngineHeader.hpp>

class Floor : public GameObject, Collidable
{
public:

	Floor() : GameObject(0, SCREEN_HEIGHT * 0.9), Collidable(this, { 0,0, SCREEN_WIDTH, 100 }),
		mShape(mPosition.x, mPosition.y, SCREEN_WIDTH,100)
	{

	}

	virtual void draw() override
	{
		mShape.draw();
	}

	virtual void update() override
	{

	}

	virtual void resolve(Collidable& other) override
	{

	}

private:
	RectangleShape mShape;

	// Унаследовано через GameObject

};