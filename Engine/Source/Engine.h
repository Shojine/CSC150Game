#pragma once


// **Core**
#include "Core/E_Timer.h"
#include "Core/EAssert.h"
#include "Core/EFile.h"

// **Systems**
// Renderer
#include "Renderer/Renderer.h"
#include "Renderer/ParticleSystem.h"
#include "Renderer/Particle.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"
#include "Renderer/Model.h"
#include "Renderer/Color.h"
// Input
#include "Input/Input.h"
// Audio
#include "Audio/Audio.h"
// **Math**
#include "Math/Vector2.h"
#include "Math/Random.h"
#include "Math/MathUtils.h"
#include "Math/Transform.h"
// **Framework** 
#include "Framework/Actor.h"
#include "Framework/Scene.h"
#include "Framework/Game.h"



#include <SDL.h>
#include <fmod.hpp>
#include <memory>

class Engine
{
public:
	Engine() = default;
	~Engine() = default;

	bool Initialize();
	void Shutdown();

	void Update();

	Renderer& GetRenderer() { return *m_renderer; }
	Input& GetInput() { return *m_input; }
	Audio& GetAudio() { return *m_audio; }
	Time& GetTime() { return *m_time; }

	ParticleSystem& GetPS() { return *m_particleSytem; }
	
	bool IsQuit() { return quit; }


private:

	bool quit{ false };

	std::unique_ptr<Renderer> m_renderer;
	std::unique_ptr<Input> m_input;
	std::unique_ptr<Audio> m_audio;
	std::unique_ptr<Time> m_time;
	std::unique_ptr<ParticleSystem> m_particleSytem;
};



