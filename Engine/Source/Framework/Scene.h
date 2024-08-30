#pragma once
#include "Object.h"
#include <list>
#include <memory>

class Renderer;
class Actor;
class Game;
class Engine;

class Scene : public Object
{
public:
	Scene(Engine* engine, Game* game = nullptr) : 
		m_game{ game },
		m_engine{engine}
	{}

	Scene(const Scene& other);

	CLASS_DECLARATION(Scene)
	CLASS_PROTOTYPE(Scene)
	
	// Inherited via Object
	void Initialize() override;
	void Update(float dt);
	void Draw(Renderer& renderer);

	void AddActor(std::unique_ptr<Actor> actor,bool initialize = false);
	void RemoveAll(bool force = false);

	template<typename T> T* GetActor();
	template<typename T> T* GetActor(const std::string& name);

public:
	Engine* m_engine{ nullptr };
	Game* m_game{ nullptr };

protected:
	std::list <std::unique_ptr<Actor>> actors;


};

template<typename T>
T* Scene::GetActor()
{
	for (auto& actor : actors)
	{
		T* result = dynamic_cast<T*>(actor.get());
		if (result) return result;
	}
	
	return nullptr;
}

template<typename T>
inline T* Scene::GetActor(const std::string& name)
{
	for (auto& actor : actors)
	{
		T* result = dynamic_cast<T*>(actor.get());
		if (result && IsEqualIgnoreCase(result->m_name, name)) return result;
	}
	return nullptr;
}
