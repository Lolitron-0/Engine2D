#pragma once
#include <Vector2.hpp>
#include <Defines.hpp>

HAS_SYSTEM(GameObjectSystem)

class GameObject
{
public:
	GameObject() = default;

	GameObject(const Vector2<float>& pos);

	GameObject(float x, float y);

	virtual void draw() = 0;

	//will be called every frame
	virtual void update() = 0;

	void setPosition(const Vector2<float>& position);	
	Vector2<float> getPosition();

	void setVelocity(const Vector2<float>& velocity);
	Vector2<float> getVelocity();

protected:
	Vector2<float> mPosition;
	Vector2<float> mVelocity;

private:
	void init();
};

