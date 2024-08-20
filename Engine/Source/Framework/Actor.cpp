#include "Actor.h"
#include "Components/RenderComponent.h"
#include "Core/Factory.h"
#include <iostream>


FACTORY_REGISTER(Actor)

void Actor::Update(float dt)
{
	if (lifespan != 0)
	{
		lifespan -= dt;
		if (lifespan <= 0)
		{
			m_destroyed = true;
		}
	}

	for (auto& component : m_components)
	{
		component->Update(dt);
	}
	/*m_transform.position += (m_velocity * dt);
	m_velocity *= 1.0f / (1.0f + m_damping * dt);*/

}

void Actor::Draw(Renderer& renderer)
{
	if (m_destroyed) return;

	for (auto& component : m_components)
	{
		RenderComponent* renderComponent = dynamic_cast<RenderComponent*>(component.get());
		if (renderComponent)
		{
			renderComponent->Draw(renderer);
		}
	}
}

void Actor::AddComponent(std::unique_ptr<Component> component)
{
	component->owner = this;
	m_components.push_back(std::move(component));
}

void Actor::Initialize()
{
	for (auto& component : m_components)
	{
		component->Initialize();
	}
}

void Actor::Read(const json_t& value)
{
	Object::Read(value);

	READ_DATA(value, tag);
	READ_DATA(value, lifespan);

	if (HAS_DATA(value, m_transform)) m_transform.Read(GET_DATA(value,m_transform));


	if (HAS_DATA(value, m_components) && GET_DATA(value, m_components).IsArray())
	{
		for (auto& componentValue : GET_DATA(value, m_components).GetArray())
		{
			std::string type;
			READ_DATA(componentValue, type);

			auto component = Factory::Instance().Create<Component>(type);
			if (!component)
			{
				std::cerr << "Could not create componetn: " << type << std::endl;
			}
			component->Read(componentValue);

			AddComponent(std::move(component));
		}
	}
	
	
}

void Actor::Write(json_t& value)
{

}
