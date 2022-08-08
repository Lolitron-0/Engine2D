#pragma once
#include <Utils.hpp>
#include <GameObject.hpp>
#include <functional>
#include <iostream>
#include <any>

HAS_SYSTEM(ColliderSystem)

class Collidable
{
public:

	/// <summary>
	/// When an object is inherited from Collidable it is automatically addded to Collidable pool
	/// /// </summary>
	/// <param name="thisObject">Pass [this] keyword here to react on collisions properly</param>
	/// <param name="box">The collider box in local coords</param>

	Collidable(GameObject* thisObject, const Rect<float>& box);
	/// <summary>
	/// When an object is inherited from Collidable it is automatically addded to Collidable pool
	/// /// </summary>
	/// <param name="thisObject">Pass [this] keyword here to react on collisions properly</param>
	/// <param name="box">The collider box in local coords</param>
	/// <param name="layer">z-index of a collidable, different layered colliders do not interact</param>
	/// <param name="name">Name of this collidable object. It is needed to divide objects in resolve method</param>
	Collidable(GameObject* thisObject, const Rect<float>& box, int layer, std::string className);

	void updateGlobalHitbox();

	void systemResolve(Collidable& other);

	bool detect(const Collidable& other);

	virtual void resolve(Collidable& other) = 0;

	int getLayer();
	//int getUserData();

protected:
	Rect<float> mLocalBox;
	int mLayer;
	std::string mName;

private:
	void init(GameObject* );

	Rect<float> mGlobalBox;
	std::shared_ptr<GameObject> mpClient;
};
