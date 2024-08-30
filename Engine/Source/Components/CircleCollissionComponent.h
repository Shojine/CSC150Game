#pragma once
#include "CollissionComponent.h"
#include "Core/Factory.h"

class CircleCollissionComponent : public CollissionComponent
{
public:
	CLASS_DECLARATION(CircleCollissionComponent)
	CLASS_PROTOTYPE(CircleCollissionComponent)
	FACTORY_REGISTER(CircleCollissionComponent)
	
	void Initialize() override;
	void Update(float dt) override;

	
	bool CheckCollision(const CollissionComponent* collision) override;
public: 
	float radius = 0.0f;
};