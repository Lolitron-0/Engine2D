#include "GameObjectSystem.hpp"


void GameObjectSystem::processAll()
{
			mTimeKoeff = mIterationClock.elapsedMs();	
			mIterationClock.restart();
			mTimeKoeff /= 3;
				
			for (int i = 0; i < mObjects.size(); i++)
			{
							mObjects[i]->setPosition(
															mObjects[i]->getPosition()+mObjects[i]->getVelocity()*mTimeKoeff); //updating position
			}
}
