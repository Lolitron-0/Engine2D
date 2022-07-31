#pragma once
#include <Utils.hpp>
#include <functional>

class Collidable
{
public:
	/// <summary>
	/// When an object is inherited from Collidable it is automatically addded to Collidable pool
	/// /// </summary>
	/// <param name="name">The collider box in absolute coords</param>
	/// <param name="box">The collider's box in absolute coords</param>
	/// <param name="velosityPtr">Pointer to velosity from GameObject to react on collisions properly</param>
	Collidable(const std::string &name, const Rect<float> &box, Vector2<float> *velosityPtr)
		: mBox(box)
	{
		mpVelosity.reset(velosityPtr);
	}

	bool detect(const Collidable &other)
	{
		return (this->mBox.intersects(other.mBox))
	}

	void resolve(Collidable &other)
	{
		mpVelosity.get()->x = 0;
		mpVelosity.get()->y = 0;
		mUserReaction();
	}

private:
	Rect<float> mBox;
	bool mIsTrigger;
	std::unique_ptr<Vector2<float>> mpVelosity;
	std::function<void()> mUserReaction;
};
