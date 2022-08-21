#include "GameObjectSystem.hpp"
#include "IterationTimer.hpp"


void GameObjectSystem::processAll()
{
				
			for (int i = 0; i < mObjects.size(); i++)
			{
							mObjects[i]->setPosition(
															mObjects[i]->getPosition()+mObjects[i]->getVelocity()*IterationTimer::getInstance().getGameSpeedKoeff()); //updating position
			}
}
