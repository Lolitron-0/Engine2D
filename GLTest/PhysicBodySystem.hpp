#pragma once
#include <ObjectSystemBase.hpp>
#include <PhysicBody.hpp>

class PhysicBodySystem : public ObjectSystemBase<PhysicBody, PhysicBodySystem>
{
public:
	// Унаследовано через ObjectSystemBase
	virtual void processAll() override;
};

