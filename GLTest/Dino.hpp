#pragma once
#include <EngineHeader.hpp>

#define GRAVITY 0.08

class Dino : public GameObject, PhysicBody, Collidable, EventListener
{
public:
	Dino(float, float);

	void draw() override;
	void update() override;

private:

	// Унаследовано через Collidable
	virtual void resolve(Collidable& other) override;

    void handle(const Event&) override;

	RectangleShape mRect;
	bool mOnGround{false};
};

