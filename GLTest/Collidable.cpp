#include <Collidable.hpp>
#include <ColliderSystem.hpp>


Collidable::Collidable(GameObject* thisObject, const Rect<float>& box)
	:mLocalBox(box), mLayer(0), mName("")
{
	init(thisObject);
}


Collidable::Collidable(GameObject* thisObject, const Rect<float>& box, int layer, std::string name)
	:mLocalBox(box), mLayer(layer), mName(name)
{
	init(thisObject);
}

void Collidable::updateGlobalHitbox()
{
	mGlobalBox = {
		mLocalBox.left + mpClient->getPosition().x,
		mLocalBox.top + mpClient->getPosition().y ,
	mLocalBox.width,
	mLocalBox.height};
}

void Collidable::systemResolve(Collidable& other)
{
	mpClient->setVelocity({ 0,0 });
	other.mpClient->setVelocity({ 0,0 });
}

bool Collidable::detect(const Collidable& other) {
	return (this->mGlobalBox.intersects(other.mGlobalBox));
}

int Collidable::getLayer()
{
	return mLayer;
}

void Collidable::init(GameObject* thisObject)
{
	mpClient.reset(thisObject);

	updateGlobalHitbox();
	ColliderSystem::getInstance().addObject(this);
}

//int Collidable::getUserData()
//{
//	return mUserData;
//}
