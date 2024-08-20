#include "Scene.h"
#include "Actor.h"
#include "Core/Factory.h"
#include "Components/CollissionComponent.h"
#include <algorithm>

void Scene::Initialize()
{
	for (auto& actor : actors)
	{
		actor->Initialize();
	}
}





void Scene::Update(float dt)
{
	// update
	for (auto& actor : actors)
	{
		if (actor->active)
		{
			actor->Update(dt);
		}
	}
	// destroy
	auto iter = actors.begin();
	while (iter != actors.end())
	{
		iter = ((*iter)->m_destroyed) ? actors.erase(iter) : ++iter;

	}

	actors.erase(std::remove_if(actors.begin(), actors.end(), [](auto& actor) { return actor->m_destroyed; }), actors.end());
	
	// collision
	for (auto& actor1 : actors)
	{
		CollissionComponent* collision1 = actor1->GetComponent<CollissionComponent>();
		if (!collision1) continue;
		
		for (auto& actor2: actors)
		{
			CollissionComponent* collision2 = actor2->GetComponent<CollissionComponent>();
			if (!collision2) continue;

			if (actor1 == actor2 || (actor1->m_destroyed || actor2->m_destroyed)) continue;
				
			if (collision1->CheckCollision(collision2))
			{
				if(actor1->OnCollisionEnter) actor1->OnCollisionEnter(actor2.get());
				if(actor2->OnCollisionEnter) actor2->OnCollisionEnter(actor1.get());
			}
		}
	}



}

void Scene::Draw(Renderer& renderer)
{
	for (auto& actor : actors)
	{
		if (actor->active)
		{
			actor->Draw(renderer);
		}
	}
}

void Scene::AddActor(std::unique_ptr<Actor> actor)
{
	actor->m_scene = this;
	actors.push_back(std::move(actor));
}

void Scene::RemoveAll()
{
	actors.clear();
}

void Scene::Read(const json_t& value)
{
	if (HAS_DATA(value, actors) && GET_DATA(value, actors).IsArray())
	{
		for (auto& actorValue : GET_DATA(value, actors).GetArray())
		{
			auto actor = Factory::Instance().Create<Actor>(Actor::GetTypename());
			actor->Read(actorValue);

			AddActor(std::move(actor));
		}
	}
}

void Scene::Write(json_t& value)
{

}

