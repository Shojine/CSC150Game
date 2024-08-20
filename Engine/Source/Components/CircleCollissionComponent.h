#pragma once
#include "CollissionComponent.h"

class CircleCollissionComponent : public CollissionComponent
{
public:
	CLASS_DECLARATION(CircleCollissionComponent)
	
	void Initialize() override;
	void Update(float dt) override;

	
	bool CheckCollision(const CollissionComponent* collision) override;
public: 
	float radius = 0.0f;
};