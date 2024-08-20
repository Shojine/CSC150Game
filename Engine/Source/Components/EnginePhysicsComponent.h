#pragma once
#include "PhysicsComponent.h"

class EnginePhysicsComponent : public PhysicsComponent
{
public:
	CLASS_DECLARATION(EnginePhysicsComponent);

	void Initialize() override;
	void Update(float dt) override;


	void ApplyFoce(const Vector2& force) override;
	void SetPosition(const Vector2& position) override;
	void SetVelocity(const Vector2& velocity) override { this->velocity = velocity; }
};