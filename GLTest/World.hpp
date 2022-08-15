#pragma once
#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include "Utils.hpp"
#include "Vector2.hpp"

class World
{
public:

	static Vector2<float> getFriction() { return gFriction; }
	//sets world friction. Values must be between 0 and 1 (otherwise it won't aply), where 0 is no friction and 1 is immediate stop
	static void setFriction(Vector2<float> friction)
	{
		if (!Math::isBetween(0.f, 1.f, friction.x) &&
			!Math::isBetween(0.f, 1.f, friction.y))
			return;
		gFriction = friction;
	}
	//sets world friction on x axis. Value must be between 0 and 1 (otherwise it won't aply), where 0 is no friction and 1 is immediate stop
	static void setFrictionX(float value)
	{
		if (!Math::isBetween(0.f, 1.f, value)) return;
		gFriction.x = value;
	}
	//sets world friction on y axis. Value must be between 0 and 1 (otherwise it won't aply), where 0 is no friction and 1 is immediate stop
	static void setFrictionY(float value)
	{
		if (!Math::isBetween(0.f, 1.f, value)) return;
		gFriction.y = value;
	}

	static Vector2<float> getGravity() { return gGravity; }
	//value that adds to velocity every frame, positive values mean right and bottom
	static void setGravity(Vector2<float> gravity)
	{
		if (!Math::isBetween(0.f, 1.f, gravity.x) &&
			!Math::isBetween(0.f, 1.f, gravity.y))
			return;
		gGravity = gravity;
	}
	//value that adds to x velocity every frame, positive values mean right
	static void setGravityX(float value)
	{
		gGravity.x = value;
	}
	//value that adds to y velocity every frame, positive values mean down
	static void setGravityY(float value)
	{
		gGravity.y = value;
	}

private:
	static Vector2<float> gFriction;
	static Vector2<float> gGravity;
	
};



#endif // !WORLD_H
