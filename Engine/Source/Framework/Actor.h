#pragma once
#include "Object.h"
#include "../Math/Transform.h"
#include "Components/Component.h"
#include <string>
#include <vector>
#include <memory>
#include <functional>


class Renderer;
class Scene;


class Actor : public Object
{
public:
	Actor() = default;
	Actor(const Transform& transform) : m_transform{ transform } {}
	Actor(const Actor& other);

	CLASS_DECLARATION(Actor)
	CLASS_PROTOTYPE(Actor)
	
	void Initialize() override;
	virtual void Update(float dt);
	virtual void Draw(Renderer& renderer);

	std::function<void(Actor*)> OnCollisionEnter;
	std::function<void(Actor*)> OnCollisionExit;

	void AddComponent(std::unique_ptr<Component> component);

	template<typename T>
	T* GetComponent();

	template<typename T>
	std::vector<T*> GetComponents();
	
	friend class Scene;

public:
	std::string tag;
	float lifespan = 0;
	bool m_destroyed = false;
	Transform m_transform;
	Scene* m_scene{ nullptr };
protected:

	std::vector<std::unique_ptr<Component>> m_components;

};

template<typename T>
inline T* Actor::GetComponent()
{
	for (auto& component : m_components)
	{
		T* result = dynamic_cast<T*>(component.get());
		if (result) return result;
	}

	return nullptr;
}

template<typename T>
inline std::vector<T*> Actor::GetComponents()
{
	std::vector<T*> components;
	for (auto& component : m_components)
	{
		T* result = dynamic_cast<T*>(component.get());
		if (result) components.push_back(result);
	}

	return components;
}
