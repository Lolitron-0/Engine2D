#pragma once
#include <EngineHeader.hpp>

class Cactus : public GameObject, Collidable, PhysicBody
{
public:

	Cactus(int x, int y);

	virtual void draw() override;

	virtual void update() override;


	virtual void resolve(Collidable& other) override;

private:

	//Sprite mShape;


};

