#pragma once
#include "Math/Transform.h"
#include <box2d/box2d.h>

class RigidBody
{
public:

	enum Shape
	{
		BOX,
		CAPSULE,
		CIRCLE,
		CHAIN
	};

	struct def_t
	{
		// body
		float gravityScale = 1;
		float damping = 0;
		float angularDamping = 0.2f;
		bool  constrainAngle = false;
		bool  isDynamic = true;

		// shape
		float friction = 0.3f;
		float restitution = 0.5f;
		float density = 1.0f;
		bool isSensor = false;

		Shape shape = Shape::BOX;

		class Actor* actor{ nullptr };
	};

public:
	RigidBody(const Transform& transform, const Vector2& size, const def_t& def, const class Physics& physics);
	~RigidBody();

	void SetTransform(const Vector2& position, float rotation);
	Vector2 GetPosition();

	float GetAngle();

	virtual void ApplyForce(const Vector2& force);
	void SetVelocity(const Vector2& velocity);
	Vector2 GetVelocity();

	virtual void ApplyTorque(float torque);
	void SetAngularVelocity(float velocity);

private:
	b2BodyId m_bodyId{ b2_nullBodyId };
};