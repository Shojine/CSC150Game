#pragma once
#include"Font.h"
#include"Renderer.h"
#include"Color.h"


class Text 
{
public:
	Text() = default;
	Text(res_t<Font> font) : m_font{ font } {}
	~Text();

	void SetFont(res_t<Font> font) { m_font = font; }

	bool Create(Renderer& renderer, const std::string& text, const Color& color);
	void Draw(Renderer& renderer, int x, int y,float angle = 0);
	res_t<Texture> GetTexture() { return m_texture; }

private:
	res_t<Font> m_font{ nullptr };
	res_t<Texture> m_texture{ nullptr };
};

