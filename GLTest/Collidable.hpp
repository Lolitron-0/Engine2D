#pragma once
#include "Utils.hpp"
#include "GameObject.hpp"
#include <functional>
#include <iostream>
#include <any>
#include <memory>

HAS_SYSTEM(ColliderSystem)

class Collidable
{
public:
	/// <summary>
	/// When an object is inherited from Collidable it is automatically addded to Collidable pool through this constructor
	/// /// </summary>
	/// <param name="thisObject">Pass [this] keyword here to react on collisions properly</param>
	/// <param name="box">The collider box in local coords</param>
	/// <param name="layer">z-index of a collidable, different layered colliders do not interact</param>
	/// <param name="name">Name of this collidable object. It is needed to divide objects in resolve method</param>
	Collidable(GameObject* thisObject, const Rect<float>& box, bool isStatic, int layer, std::string className);

	void updateGlobalHitbox();

	void systemResolve(Collidable& other, const Rect<float>& intersection);

	bool detect(const Collidable& other, Rect<float>& intersection);

	virtual void resolve(Collidable& other) = 0;

	bool isStatic();
	int getLayer();
	std::string getName();
	//int getUserData();

protected:
	Rect<float> mLocalBox;
	int mLayer;
	bool mStatic;
	std::string mName;

private:
	enum class Side {
		top,
		right,
		bottom,
		left
	};

	void init(GameObject* );
	Side determineCollisionSide(const Rect<float>& intersection);

	Rect<float> mGlobalBox;
	std::shared_ptr<GameObject> mpClient;
};
