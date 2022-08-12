#include <Collidable.hpp>
#include <ColliderSystem.hpp>


Collidable::Collidable(GameObject* thisObject, const Rect<float>& box, bool isStatic, int layer, std::string name)
	:mLocalBox(box), mLayer(layer), mName(name), mStatic(isStatic)
{
	init(thisObject);
}

void Collidable::updateGlobalHitbox()
{
	mGlobalBox = {
		mLocalBox.x + mpClient->getPosition().x,
		mLocalBox.y + mpClient->getPosition().y ,
	mLocalBox.width,
	mLocalBox.height};
}

void Collidable::systemResolve(Collidable& other)
{
	//TODO: bump
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

std::string Collidable::getName()
{
	return mName;
}

bool Collidable::isStatic()
{
	return mStatic;
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
