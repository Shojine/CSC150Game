#pragma once
#include "Vector2.h"

struct Transform
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
};

