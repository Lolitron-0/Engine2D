#pragma once
#include <Utils.hpp>
#include <functional>



class CollidableBase
{

};

/// <summary>
/// Note: DO NOT inherit this class directly, use COLLIDABLE_INHERITANCE macro instead to provide correct CRTP usage
/// </summary>
/// <typeparam name="Derived">This is the type of your class (which you inherit)</typeparam>
template <class Derived>
class Collidable : public CollidableBase
{
public:
	
	/// <summary>
	/// When an object is inherited from Collidable it is automatically addded to Collidable pool
	/// /// </summary>
	/// <param name="box">The collider box in absolute coords</param>
	/// <param name="velosityPtr">Pointer to velosity from GameObject to react on collisions properly</param>
	Collidable(const Rect<float>& box, Vector2<float>* velosityPtr)
		:mBox(box)
	{
		mpVelosity.reset(velosityPtr);
	}

	template <class OtherDerived>
	bool detect(const Collidable<OtherDerived>& other) {
		return (this->mBox.intersects(other.mBox))
	}

	template <class OtherDerived>
	void resolve(Collidable<OtherDerived>& other) {
		mpVelosity.get()->x =0;
		mpVelosity.get()->y =0;
		mUserReaction();
	}

private:

	Rect<float> mBox;
	bool mIsTrigger;
	std::unique_ptr<Vector2<float>> mpVelosity;
	std::function<void()> mUserReaction;
};

//Macro to use CRTP correctly. [Type] is a derived class
#define COLLIDABLE_INHERITANCE(Type) public Collidable<Type>

//CRTP in Collider and GameObject to pass in resolve and make switch by type
