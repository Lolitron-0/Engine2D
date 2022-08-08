#pragma once
#include <iostream>
#include <vector>
#include <ObjectSystemBase.hpp>
#include <GameObject.hpp>

class GameObjectSystem : public ObjectSystemBase<GameObject,GameObjectSystem>
{
public:
	// ������������ ����� ObjectSystemBase
	virtual void processAll() override;
};

