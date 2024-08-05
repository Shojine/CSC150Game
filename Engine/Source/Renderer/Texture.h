#pragma once
#include "../Renderer/Renderer.h"
#include "../Math/Vector2.h"
#include "../Recources/Resource.h"
#include<string>
#include<SDL_image.h>

class Renderer;

class Texture : Resource
{
public:
	Texture() = default;
	~Texture();
	
	// Inherited via Recource
	bool Create(std::string name, ...) override;
	bool Load(const std::string& filename, Renderer& renderer);

	Vector2 GetSize();

	friend class Renderer;

private:
	struct SDL_Texture* m_texture{ nullptr };



};