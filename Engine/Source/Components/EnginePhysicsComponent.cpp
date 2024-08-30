#include "EnginePhysicsComponent.h"
#include "Framework/Actor.h"
#include "Core/Factory.h"
#include "Core/EAssert.h"

FACTORY_REGISTER(EnginePhysicsComponent)

void EnginePhysicsComponent::Initialize()
{
}

void EnginePhysicsComponent::Update(float dt)
{
	velocity += acceleration * dt;
	owner->m_transform.position += velocity * dt;
	velocity *= 1.0f / (1.0f + damping * dt);

	acceleration = Vector2{ 0,0 };
}



void EnginePhysicsComponent::SetPosition(const Vector2& position)
{
	owner->m_transform.position = position;
}



void EnginePhysicsComponent::ApplyForce(const Vector2& force)
{
	assert(mass != 0);
	//f = m * a
	// a = f / m
	acceleration += force / mass;
}

void EnginePhysicsComponent::ApplyTorque(float torque)
{
}

void EnginePhysicsComponent::Read(const json_t& value)
{
	PhysicsComponent::Read(value);
}

void EnginePhysicsComponent::Write(json_t& value)
{
}