#include "Engine.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>


void f()
{
	int i = 5;
	i++;
	std::cout << i << std::endl;
}

int main(int argc, char* argv[])
{
	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Initialize();

	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << std::endl;
	{
		res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("small.png", engine->GetRenderer());
		res_t<Font> font = ResourceManager::Instance().Get<Font>("ArcadeClassic.ttf", 12);
		std::unique_ptr<Text> text = std::make_unique<Text>(font);
		text->Create(engine->GetRenderer(), "Hello!", { 1, 1, 0, 1 });

		Transform t{ {30,30} };
		std::unique_ptr<Actor> actor = std::make_unique<Actor>(t);
		std::unique_ptr<TextureComponent> component = std::make_unique<TextureComponent>();
		component->texture = texture;
		actor->AddComponent(std::move(component));



		while (!engine->IsQuit())
		{
			//update
			engine->Update();

			actor->Update(engine->GetTime().GetDeltaTime());

			engine->GetRenderer().SetColor(0, 0, 0, 0);
			engine->GetRenderer().BeginFrame();
			//draw
			text->Draw(engine->GetRenderer(), 400, 400);
			engine->GetRenderer().DrawTexture(texture.get(), 30, 30, 0);

			//actor->Draw(engine->GetRenderer());
			engine->GetRenderer().EndFrame();

		}
	}
	ResourceManager::Instance().Clear();
	engine->Shutdown();

	return 0;
}
