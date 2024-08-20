#include "Engine.h"
#include "Components/PlayerComponent.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>




int main(int argc, char* argv[])
{

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Initialize();


	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << std::endl;

	std::string s;
	File::ReadFile("Scenes/scene.json", s);
	std::cout << s << std::endl;


	rapidjson::Document document;
	Json::Load("Scenes/scene.json", document);

	std::unique_ptr<Scene> scene = std::make_unique<Scene>(engine.get());
	scene->Read(document);
	scene->Initialize();
		
		while (!engine->IsQuit())
		{
			//update
			engine->Update();
			scene->Update(engine->GetTime().GetDeltaTime());
			
			auto* actor = scene->GetActor<Actor>("text");
			if (actor)
			{
				actor->m_transform.rotation += 90 * engine->GetTime().GetDeltaTime();
			}

			

			engine->GetRenderer().SetColor(0, 0, 0, 0);
			engine->GetRenderer().BeginFrame();

			//draw
			scene->Draw(engine->GetRenderer());

			engine->GetRenderer().EndFrame();

		}

	scene->RemoveAll();
	ResourceManager::Instance().Clear();
	engine->Shutdown();

	return 0;
}
