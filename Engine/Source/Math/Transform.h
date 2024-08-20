#pragma once
#include "Vector2.h"
#include "Core/Serializable.h"

struct Transform : public Serializable
{
	Vector2 position;
	float rotation;
	float scale;

	Transform() = default;
	Transform(Vector2 postion, float rotation = 0, float scale = 1) :
		position{ postion },
		rotation{ rotation },
		scale{ scale }
	{}

	// Inherited via Serializable
	void Read(const json_t& value) override;
	void Write(json_t& value) override;
};

