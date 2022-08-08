#pragma once
#include <vector>
#include <iostream>
#include <ObjectSystemBase.hpp>
#include <Collidable.hpp>

class ColliderSystem : public ObjectSystemBase<Collidable,ColliderSystem>
{
public:
	// ������������ ����� ObjectSystemBase
	virtual void processAll() override;

	ColliderSystem();
private:
};


