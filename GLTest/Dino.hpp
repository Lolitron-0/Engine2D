#pragma once
#include <EngineHeader.hpp>

#define GRAVITY 0.08

class Dino : public GameObject, PhysicBody, Collidable
{
public:
	Dino(float, float);

	void draw() override;
	void update() override;

private:
	RectangleShape mRect;

	// Унаследовано через Collidable
	virtual void resolve(Collidable& other) override;
};

