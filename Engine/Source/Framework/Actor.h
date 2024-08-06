#pragma once
#include "Object.h"
#include "../Math/Transform.h"
#include "Components/Component.h"
#include "Renderer/Model.h"
#include <string>
#include <vector>
#include <memory>


class Renderer;
class Scene;
class Model;

class Actor : public Object
{
public:
	Actor() = default;
	Actor(const Transform& transform) : m_transform{ transform } {}
	
	virtual void Update(float dt);
	virtual void Draw(Renderer& renderer);

	void AddComponent(std::unique_ptr<Component> component);


	void SetDamping(float damping) { m_damping = damping; }
	void SetLifeSpan(float lifespan) { m_lifespan = lifespan; }
	void SetTag(const std::string& tag) { m_tag = tag; }
	
	const std::string& GetTag() { return m_tag; }

	const Transform& GetTransform() { return m_transform; }


	
	virtual void OnCollision(Actor* actor) {};
	float GetRadius() { return (m_model) ? m_model->GetRadius() * m_transform.scale : 0; }
	

	friend class Scene;

protected:
	std::string m_tag;
	bool m_destroyed = false;
	float m_lifespan = 0;

	Model* m_model;
	Transform m_transform;
	Vector2 m_velocity{ 0,0 };
	float m_damping{ 0 };

	
	 Scene* m_scene{ nullptr };

	 std::vector<std::unique_ptr<Component>> m_components;

	 // Inherited via Object
	 void Initialize() override;
};
