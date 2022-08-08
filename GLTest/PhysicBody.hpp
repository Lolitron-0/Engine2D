#pragma once
#include <GameObject.hpp>
#include <iostream>

HAS_SYSTEM(PhysicBodySystem)

class PhysicBody
{
public:
	PhysicBody(GameObject* thisObject, float gravityY);
	PhysicBody(GameObject* thisObject);

	Vector2<float> getFriction();
	//Values must be between 0 and 1 (otherwise it won't aply), where 0 is no friction and 1 is immediate stop
	void setFriction(Vector2<float> friction);
	//Value must be between 0 and 1 (otherwise it won't aply), where 0 is no friction and 1 is immediate stop
	void setFrictionX(float value);
	//Value must be between 0 and 1 (otherwise it won't aply), where 0 is no friction and 1 is immediate stop
	void setFrictionY(float value);

	Vector2<float> getGravity();
	//value that adds to velocity every frame, positive values mean right and bottom
	void setGravity(Vector2<float> gravity);
	//value that adds to x velocity every frame, positive values mean right
	void setGravityX(float value);
	//value that adds to y velocity every frame, positive values mean down
	void setGravityY(float value);


	void update();
private:

	void init(GameObject* );

	std::shared_ptr<GameObject> mpClient;
	Vector2<float> mFriction;
	Vector2<float> mGravity;
};

