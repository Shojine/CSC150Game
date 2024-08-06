#include "TextureComponent.h"
#include "Renderer/Renderer.h"
//#include "Resources/Recourcemanager"
#include "Framework/Actor.h"

void TextureComponent::Initialize()
{
	if (!textureName.empty())
	{
		//texture = ResoucrceManager::Instance().Get<Texture>();
	}
}

void TextureComponent::Update(float dt)
{
	//
}

void TextureComponent::Draw(Renderer& renderer)
{
	Transform transform = owner->GetTransform();
	renderer.DrawTexture(texture.get(), transform.position.x, transform.position.y,transform.scale);
}
