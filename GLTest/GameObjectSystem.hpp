#pragma once
#include <iostream>
#include <vector>
#include "ObjectSystemBase.hpp"
#include "GameObject.hpp"

class GameObjectSystem : public ObjectSystemBase<GameObject,GameObjectSystem>
{
public:
	 
	virtual void processAll() override;
private:
};

