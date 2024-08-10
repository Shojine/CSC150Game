#include "Engine.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>


int main(int argc, char* argv[])
{
	Factory::Instance().Register<Actor>(Actor::GetTypename());
	auto a = Factory::Instance().Create("Actor");

	Factory::Instance().Register<TextureComponent>(TextureComponent::GetTypename());

	

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Initialize();

	File::SetFilePath("Assets");
	std::cout << File::GetFilePath() << std::endl;

	std::string s;
	File::ReadFile("text.txt", s);
	std::cout << s << std::endl;

	rapidjson::Document document;
	Json::Load("text.txt", document);

	std::string name;
	int age;
	float speed;
	bool IsDed;
	Vector2 position;
	Color color;

	READ_DATA(document, name);
	READ_DATA(document, age);
	READ_DATA(document, speed);
	READ_DATA(document, IsDed);
	READ_DATA(document, position);
	READ_DATA(document, color);
	// show the data
	std::cout << name << " " << age << " " << speed << " " << IsDed << std::endl;
	std::cout << position.x << " " << position.y << std::endl;
	std::cout << color.r << " " << color.g << " " << color.b << " " << color.a << std::endl;



	{
		res_t<Texture> texture = ResourceManager::Instance().Get<Texture>("small.png", engine->GetRenderer());
		res_t<Font> font = ResourceManager::Instance().Get<Font>("ArcadeClassic.ttf", 12);
		std::unique_ptr<Text> text = std::make_unique<Text>(font);
		text->Create(engine->GetRenderer(), "Hello!", { 1, 1, 0, 1 });

		Transform t{ {30,30} };
		std::unique_ptr<Actor> actor = Factory::Instance().Create<Actor>(Actor::GetTypename());
		actor->SetTrasnform(Transform{{30,30}});
		std::unique_ptr<TextureComponent> component = Factory::Instance().Create<TextureComponent>(TextureComponent::GetTypename());
		
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

			actor->Draw(engine->GetRenderer());
			engine->GetRenderer().EndFrame();

		}
	}
	ResourceManager::Instance().Clear();
	engine->Shutdown();

	return 0;
}
