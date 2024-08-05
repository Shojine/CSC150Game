#pragma once
#include "../Recources/Resource.h"
#include<SDL_ttf.h>
#include <string>

class Font : Resource
{
public: 
	Font() = default;
	~Font();

	bool Create(std::string name, ...) override;
	bool Load(const std::string& name, int fontSize);

	friend class Text;

private:
	_TTF_Font* m_ttfFont{ nullptr };

	// Inherited via Recource
};