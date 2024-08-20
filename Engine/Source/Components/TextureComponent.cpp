#include "TextureComponent.h"
#include "Renderer/Renderer.h"
#include "Recources/RecourceManager.h"
#include "Framework/Actor.h"
#include "Engine.h"

FACTORY_REGISTER(TextureComponent)

void TextureComponent::Initialize()
{
	if (!textureName.empty())
	{
		texture = ResourceManager::Instance().Get<Texture>(textureName, owner->m_scene->m_engine->GetRenderer());
	}
}

void TextureComponent::Update(float dt)
{
	//
}

void TextureComponent::Draw(Renderer& renderer)
{
	Transform transform = owner->m_transform;
	renderer.DrawTexture(texture, transform);
}

void TextureComponent::Read(const json_t& value)
{
	READ_DATA_REQUIRED(value, textureName);
}

void TextureComponent::Write(json_t& value)
{
	//
}
