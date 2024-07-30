#pragma once
#include "Renderer.h"
#include "Vector2.h"
#include "Input.h"
#include "Particle.h"
#include "Random.h"
#include "E_Timer.h"
#include "MathUtils.h"
#include "Model.h"
#include "Transform.h"
#include "Audio.h"
#include "time.h"
#include "particleSystem.h"


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


extern Engine g_engine;
