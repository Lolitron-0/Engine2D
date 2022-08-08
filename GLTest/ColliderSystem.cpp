#include <ColliderSystem.hpp>

ColliderSystem::ColliderSystem():ObjectSystemBase<Collidable, ColliderSystem>()
{

}

void ColliderSystem::processAll()
{
	for (int i = 0; i < mObjects.size() - 1; i++)
	{
		for (int j = i + 1; j < mObjects.size(); j++)
		{
			mObjects[i]->updateGlobalHitbox();
			mObjects[j]->updateGlobalHitbox();

			if (mObjects[i]->getLayer()== mObjects[j]->getLayer() &&
				mObjects[i]->detect(*mObjects[j]))
			{
				mObjects[i]->systemResolve(*mObjects[j]);
				mObjects[i]->resolve(*mObjects[j]);
				mObjects[j]->resolve(*mObjects[i]);
			}
		}
	}
}
