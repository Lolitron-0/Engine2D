#include "GameObject.hpp"
#include <GameObjectSystem.hpp>

GameObject::GameObject(const Vector2<float>& pos)
	:mPosition(pos), mVelocity(0, 0)
{
	init();
}

GameObject::GameObject(float x, float y)
	: mPosition(x, y), mVelocity(0, 0)
{
	init();
}

void GameObject::setPosition(const Vector2<float>&position) { this->mPosition = position; }

Vector2<float> GameObject::getPosition() { return mPosition; }

void GameObject::setVelocity(const Vector2<float>& velocity) { this->mVelocity = velocity; }

Vector2<float> GameObject::getVelocity() { return mVelocity; }

void GameObject::init()
{
	GameObjectSystem::getInstance().addObject(this);
}
