#pragma once
#include <RectangleShape.h>
#include <GameObject.hpp>
#include <Collider.hpp>

#define GRAVITY 0.01

class Dino : public GameObject, COLLIDABLE_INHERITANCE(Dino)
{
public:
	Dino(int x, int y);

	void onKeyPressed(int key, int action);

	void draw() override;
	void update() override;

private:
	RectangleShape mRect;
};

