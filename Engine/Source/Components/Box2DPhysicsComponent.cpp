#include "Box2DPhysicsComponent.h"
#include "Engine.h"
#include <memory>


FACTORY_REGISTER(Box2DPhysicsComponent)

Box2DPhysicsComponent::Box2DPhysicsComponent(const Box2DPhysicsComponent& other)
{
	rigidBodyDef = other.rigidBodyDef;
	//if (other.m_rigidBody)
	//{
	//	m_rigidBody = std::make_unique<RigidBody>(*other.m_rigidBody.get());
	//}
}

void Box2DPhysicsComponent::Initialize()
{
	rigidBodyDef.actor = owner;
	m_rigidBody = std::make_unique<RigidBody>(owner->m_transform, size * scale, rigidBodyDef, owner->m_scene->m_engine->GetPhysics());
}

void Box2DPhysicsComponent::Update(float dt)
{
	owner->m_transform.position = m_rigidBody->GetPosition();
	owner->m_transform.rotation = m_rigidBody->GetAngle();
	velocity = m_rigidBody->GetVelocity();
}

void Box2DPhysicsComponent::ApplyForce(const Vector2& force)
{
	m_rigidBody->ApplyForce(force);
}

void Box2DPhysicsComponent::ApplyTorque(float torque)
{
	m_rigidBody->ApplyTorque(torque);
}

void Box2DPhysicsComponent::SetPosition(const Vector2& position)
{
	m_rigidBody->SetTransform(position, m_rigidBody->GetAngle());
}

void Box2DPhysicsComponent::SetVelocity(const Vector2& velocity)
{
	m_rigidBody->SetVelocity(velocity);
}



void Box2DPhysicsComponent::Read(const json_t& value)
{
	READ_DATA_NAME(value, "gravityScale", rigidBodyDef.gravityScale);
	READ_DATA_NAME(value, "damping", rigidBodyDef.damping);
	READ_DATA_NAME(value, "angularDamping", rigidBodyDef.angularDamping);
	READ_DATA_NAME(value, "constrainAngle", rigidBodyDef.constrainAngle);
	READ_DATA_NAME(value, "isDynamic", rigidBodyDef.isDynamic);
	READ_DATA_NAME(value, "friction", rigidBodyDef.friction);
	READ_DATA_NAME(value, "restitution", rigidBodyDef.restitution);
	READ_DATA_NAME(value, "density", rigidBodyDef.density);
	READ_DATA_NAME(value, "isSensor", rigidBodyDef.isSensor);

	std::string shape;

	READ_DATA(value, shape);

	if (IsEqualIgnoreCase(shape,"capsule")) rigidBodyDef.shape = RigidBody::Shape::CAPSULE;
	else if (IsEqualIgnoreCase(shape,"circle")) rigidBodyDef.shape = RigidBody::Shape::CIRCLE;

	READ_DATA(value, size);
	READ_DATA(value, scale);
}

void Box2DPhysicsComponent::Write(json_t& value)
{
	//
}