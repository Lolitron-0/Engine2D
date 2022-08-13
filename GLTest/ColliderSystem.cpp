#include <ColliderSystem.hpp>

ColliderSystem::ColliderSystem():ObjectSystemBase<Collidable, ColliderSystem>()
{

}

void ColliderSystem::processAll()
{
	std::shared_ptr<Rect<float>> intersection(new Rect<float>());
	for (int i = 0; i < mObjects.size() - 1; i++)
	{
		for (int j = i + 1; j < mObjects.size(); j++)
		{
			mObjects[i]->updateGlobalHitbox();
			mObjects[j]->updateGlobalHitbox();
			if (mObjects[i]->getLayer()== mObjects[j]->getLayer() &&
				mObjects[i]->detect(*mObjects[j], *intersection))
			{
				if(!mObjects[i]->isStatic())
					mObjects[i]->systemResolve(*mObjects[j],*intersection);
				if(!mObjects[j]->isStatic())
					mObjects[j]->systemResolve(*mObjects[i], *intersection);
				mObjects[i]->resolve(*mObjects[j]);
				mObjects[j]->resolve(*mObjects[i]);
			}
		}
	}
}
