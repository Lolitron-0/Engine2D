#include "PhysicBodySystem.hpp"

void PhysicBodySystem::processAll()
{
	for (int i = 0; i < mObjects.size(); i++)
	{
		mObjects[i]->update();
	}
}
