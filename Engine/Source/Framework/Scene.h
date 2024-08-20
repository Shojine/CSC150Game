#pragma once
#include "Object.h"
#include <list>
#include< memory>

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
	CLASS_DECLARATION(Scene);
	// Inherited via Object
	void Initialize() override;
	void Update(float dt);
	void Draw(Renderer& renderer);

	void AddActor(std::unique_ptr<Actor> actor);
	void RemoveAll();

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
		if (result && IsEquealIgnoreCase(result->name, name)) return result;
	}
	return nullptr;
}
