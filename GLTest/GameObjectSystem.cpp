#include "GameObjectSystem.hpp"


void GameObjectSystem::processAll()
{
	for (int i = 0; i < mObjects.size(); i++)
	{
		mObjects[i]->setPosition(mObjects[i]->getPosition()+mObjects[i]->getVelocity()); //updating position
	}
}
