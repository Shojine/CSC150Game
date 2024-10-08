#include "SpaceGame.h"
#include "Engine.h"
#include <memory>

bool SpaceGame::Initialize()
{
	rapidjson::Document document;
	Json::Load("Scenes/scene.json", document);

	m_scene = std::make_unique<Scene>(m_engine);
	m_scene->Read(document);
	m_scene->Initialize();

	ADD_OBSERVER(PlayerDead, SpaceGame::OnPlayerDead);
    return true;
}

void SpaceGame::Shutdown()
{

	m_scene->RemoveAll();
}

void SpaceGame::Update(float dt)
{

	m_scene->Update(dt);
}

void SpaceGame::Draw(Renderer& renderer)
{
	m_scene->Draw(renderer);
}

void SpaceGame::OnPlayerDead(const Event& event)
{
	std::cout << "game player dead" << std::endl;
	
}

void SpaceGame::OnAddPoints(const Event& event)
{
	m_score += 100;
}
