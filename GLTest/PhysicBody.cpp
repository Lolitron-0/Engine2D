#include "PhysicBody.hpp"
#include "PhysicBodySystem.hpp"
#include "IterationTimer.hpp"

PhysicBody::PhysicBody(GameObject* thisObject, float gravityY)
    :mGravity(0,gravityY), mFriction(0,0)
{
    init(thisObject);
}

PhysicBody::PhysicBody(GameObject* thisObject)
    : mGravity(0, 0), mFriction(0, 0)
{
    init(thisObject);
}

void PhysicBody::init(GameObject* thisObject)
{
    mpClient.reset(thisObject); 
    PhysicBodySystem::getInstance().addObject(this);
}

void PhysicBody::update()
{
    mpClient->setVelocity(mpClient->getVelocity() + this->mGravity * IterationTimer::getInstance().getGameSpeedKoeff());
    mpClient->setVelocity(mpClient->getVelocity() * (1.f -this->mFriction)); //TODO
}



#pragma region GET_SET

inline Vector2<float> PhysicBody::getFriction() { return mFriction; }

inline void PhysicBody::setFriction(Vector2<float> friction)
{
    if (!Math::isBetween(0.f, 1.f, friction.x) &&
        !Math::isBetween(0.f, 1.f, friction.y))
        return;
    mFriction = friction;
}

inline void PhysicBody::setFrictionX(float value)
{
    if (!Math::isBetween(0.f, 1.f, value)) return;
    mFriction.x = value;
}

inline void PhysicBody::setFrictionY(float value)
{
    if (!Math::isBetween(0.f, 1.f, value)) return;
    mFriction.y = value;
}


inline Vector2<float> PhysicBody::getGravity() { return mGravity; }

inline void PhysicBody::setGravity(Vector2<float> gravity)
{
    if (!Math::isBetween(0.f, 1.f, gravity.x) &&
        !Math::isBetween(0.f, 1.f, gravity.y))
        return;
    mGravity = gravity;
}

inline void PhysicBody::setGravityX(float value)
{
    mGravity.x = value;
}

inline void PhysicBody::setGravityY(float value)
{
    mGravity.y = value;
}

#pragma endregion
