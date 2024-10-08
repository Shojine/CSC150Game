#include "TextureComponent.h"
#include "Renderer/Renderer.h"
#include "Recources/RecourceManager.h"
#include "Framework/Actor.h"
#include "Core/Factory.h"
#include "Engine.h"

FACTORY_REGISTER(TextureComponent)

void TextureComponent::Initialize()
{
	if (!textureName.empty())
	{
		texture = ResourceManager::Instance().Get<Texture>(textureName, owner->m_scene->m_engine->GetRenderer());
	}
	if (texture && source.w == 0 && source.h == 0)
	{
		source.x = 0;
		source.y = 0;
		// set source from texture width and height
		source.w = (int)texture->GetSize().x;
		source.h = (int)texture->GetSize().y;
	}
}

void TextureComponent::Update(float dt)
{
	//
}

void TextureComponent::Draw(Renderer& renderer)
{
	Transform transform = owner->m_transform;
	renderer.DrawTexture(texture, transform,source);
}

void TextureComponent::Read(const json_t& value)
{
	READ_DATA(value, textureName);
	READ_DATA(value, source);
}

void TextureComponent::Write(json_t& value)
{
	//
}
