#pragma once
#include <EngineHeader.hpp>

#define GRAVITY 0.08

class Dino : public GameObject, PhysicBody, Collidable, KeyListener
{
public:
	Dino(float, float);
	
	void draw() override;
	void update() override;

private:

	// ������������ ����� Collidable
	virtual void resolve(Collidable& other) override;

	// ������������ ����� KeyListener
	virtual void onKeyDown(const KeyEventArgs& args) override;
	virtual void onKeyUp(const KeyEventArgs& args) override;

	RectangleShape mRect;
	bool mOnGround{false};
};

