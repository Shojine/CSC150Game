#pragma once
#include "Component.h"

class CollissionComponent : public Component
{
public: 
	virtual bool CheckCollision(const CollissionComponent* collision) = 0;
};