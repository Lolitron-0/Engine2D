#pragma once
#include <EngineHeader.hpp>
#include <Window.hpp>

class Floor : public GameObject, Collidable
{
public:

	Floor(const Rect<float>& rect) : GameObject(rect.x, rect.y), Collidable(this, { 0,0, rect.width, rect.height },true,0,"floor"),
		mShape(rect.x, rect.y, rect.width,rect.height)
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