#include <Collidable.hpp>
#include <ColliderSystem.hpp>
#include <Window.hpp>


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

void Collidable::systemResolve(Collidable& other, const Rect<float>& intersection)
{
	
	glBegin(GL_TRIANGLE_FAN);
		glColor3ub(255,255,255);
		glVertex2f(Window::getInstance().screenToGlX(intersection.x), Window::getInstance().screenToGlY(intersection.y));
		glVertex2f(Window::getInstance().screenToGlX(intersection.x+ intersection.width), Window::getInstance().screenToGlY(intersection.y));
		glVertex2f(Window::getInstance().screenToGlX(intersection.x+ intersection.width), Window::getInstance().screenToGlY(intersection.y + intersection.height));
		glVertex2f(Window::getInstance().screenToGlX(intersection.x), Window::getInstance().screenToGlY(intersection.y + intersection.height));
	glEnd();

	switch (determineCollisionSide(intersection))
	{
	case Side::bottom:
		this->mpClient->setPosition(mpClient->getPosition().withYAdded(-intersection.height));	
		this->mpClient->setVelocity(mpClient->getVelocity().withY(0));
		break;
	case Side::top:
		this->mpClient->setPosition(mpClient->getPosition().withYAdded(intersection.height));
		this->mpClient->setVelocity(mpClient->getVelocity().withY(0));
		break;
	case Side::right:
		this->mpClient->setPosition(mpClient->getPosition().withXAdded(-intersection.width));
		this->mpClient->setVelocity(mpClient->getVelocity().withX(0));
		break;
	case Side::left:
		this->mpClient->setPosition(mpClient->getPosition().withXAdded(intersection.width));
		this->mpClient->setVelocity(mpClient->getVelocity().withX(0));		
		break;
	default:
		break;
	}

	//other.mpClient->setVelocity({ 0,0 });
}

bool Collidable::detect(const Collidable& other, Rect<float>& intersection) {
	return (this->mGlobalBox.intersects(other.mGlobalBox, intersection));
}

bool Collidable::isStatic()
{
	return mStatic;
}

int Collidable::getLayer()
{
	return mLayer;
}

std::string Collidable::getName()
{
	return mName;
}


void Collidable::init(GameObject* thisObject)
{
	mpClient.reset(thisObject);

	updateGlobalHitbox();
	ColliderSystem::getInstance().addObject(this);
}

Collidable::Side Collidable::determineCollisionSide(const Rect<float>& intersection)
{
	if (intersection.width > intersection.height)
	{
		if (intersection.getTopLeft().y == this->mGlobalBox.getTopLeft().y)
			return Side::top;
		else if(intersection.getBottomLeft().y == this->mGlobalBox.getBottomLeft().y)
			return Side::bottom;
	}
	else
	{
		if (intersection.getTopLeft().x == this->mGlobalBox.getTopLeft().x)
			return Side::left;
		else if (intersection.getTopRight().x == this->mGlobalBox.getTopRight().x)
			return Side::right;
	}
}

//int Collidable::getUserData()
//{
//	return mUserData;
//}
