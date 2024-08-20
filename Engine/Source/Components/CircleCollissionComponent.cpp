#include "CircleCollissionComponent.h"
#include "Framework/Actor.h"


void CircleCollissionComponent::Initialize()
{
}

void CircleCollissionComponent::Update(float dt)
{
}

bool CircleCollissionComponent::CheckCollision(const CollissionComponent* collision)
{
	float r1 = radius;
	float r2 = (dynamic_cast<const CircleCollissionComponent*>(collision))->radius;

	float distance = owner->m_transform.position.Distance(collision->owner->m_transform.position);

	return (distance <= (r1 + r2));
}

void CircleCollissionComponent::Read(const json_t& value)
{
	READ_DATA(value, radius);
}

void CircleCollissionComponent::Write(json_t& value)
{
}