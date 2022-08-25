#pragma once
#include <iostream>
#include <vector>
#include "../Utils/Utils.hpp"

//We pass CRTP Derived class to create singleton instance of it (it is not abstract)
template <class Object, class Derived>
class ObjectSystemBase : public Singleton<Derived>
{
public:
	virtual void processAll() = 0;

	void addObject(Object* object)
	{
		mObjects.push_back(object);
	}

protected:

	std::vector<Object*> mObjects;
};

