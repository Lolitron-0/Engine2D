#pragma once
#include <Vector2.hpp>

class GameObject
{

public:
	GameObject() = default;
	GameObject(const Vector2<float>& pos)
		:mPosition(pos), mVelosity(0,0)
	{}
	GameObject(float x, float y)
		:mPosition(x,y), mVelosity(0,0)
	{}

	virtual void draw() = 0;

	//will be called every frame
	virtual void update() = 0;

protected:

	Vector2<float> mPosition;
	Vector2<float> mVelosity;
};

