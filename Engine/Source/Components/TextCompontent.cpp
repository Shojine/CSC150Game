#include "TextCompontent.h"
#include "Recources/RecourceManager.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"

void TextComponent::Initialize()
{
	if (!fontname.empty())
	{
		auto font = ResourceManager::Instance().Get<Font>(fontname, fontSize);
		m_text = std::make_unique<Text>(font);
	}
}

void TextComponent::Update(float dt)
{
}

void TextComponent::Draw(Renderer& renderer)
{
	if (textChanged)
	{
		textChanged = false;
		m_text->Create(renderer,text,color);
	}
	renderer.DrawTexture(m_text->GetTexture(), owner->m_transform);
}

void TextComponent::SetText(const std::string& text)
{
	if (this->text != text)
	{
	this->text = text;
	textChanged = true;
	}
}

void TextComponent::Read(const json_t& value)
{
	READ_DATA(value, text);
	READ_DATA(value, fontname);
	READ_DATA(value, fontSize);
	READ_DATA(value, color);
}

void TextComponent::Write(json_t& value)
{

}