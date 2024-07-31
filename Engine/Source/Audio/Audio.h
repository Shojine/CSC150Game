#pragma once
#include <fmod.hpp>
#include<string>
#include <map>

class Audio
{
public:
	Audio() = default;
	~Audio() = default;

	bool Initialize();
	void ShutDown();
	bool AddSound(const std::string& name);
	bool PlaySound(const std::string& name);


	void Update();
private:
	FMOD::System* m_audio{ nullptr };
	std::map<std::string,FMOD::Sound*> m_sounds;
};