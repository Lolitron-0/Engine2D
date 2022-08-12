#pragma once
#include <EngineHeader.hpp>

class Cactus : public GameObject, Collidable, PhysicBody
{
public:

	Cactus(int x, int y);

	// Унаследовано через GameObject
	virtual void draw() override;

	virtual void update() override;


	// Унаследовано через Collidable
	virtual void resolve(Collidable& other) override;

private:

	RectangleShape mShape;


};

