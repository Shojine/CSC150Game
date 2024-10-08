#include "Engine.h"
#include <crtdbg.h>

Engine g_engine;


bool Engine::Initialize()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	m_renderer = std::make_unique<Renderer>();
	m_input = std::make_unique<Input>();
	m_audio = std::make_unique<Audio>();
	m_time = std::make_unique<Time>();
	m_particleSytem = std::make_unique<ParticleSystem>();
	m_physics = std::make_unique<Physics>();
	//m_textureanimation = std::make_unique <TextureAnimationComponent>();
	

	m_renderer->Initialize();
	m_renderer->CreateWindow("Game Engine", 800, 600);
	m_input->Initialize();
	m_audio->Initialize();
	m_physics->Initialize();

	FMOD::System* audio;
	FMOD::System_Create(&audio);

	void* extradriverdata = nullptr;
	audio->init(32, FMOD_INIT_NORMAL, extradriverdata);

	

	return true;
}

void Engine::Shutdown()
{
	m_renderer->ShutDown();
	m_input->ShutDown();
	m_audio->ShutDown();
	m_physics->Shutdown();

	_CrtMemDumpAllObjectsSince(NULL);
}

void Engine::Update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			quit = true;
		}
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
		{
			quit = true;
		}
	}

	m_time->Tick();

	m_input->Update();
	m_audio->Update();
	m_particleSytem->Update(m_time->GetDeltaTime());
	m_physics->Update(m_time->GetDeltaTime());
	//m_textureanimation->Update(m_time->GetDeltaTime());
	
}
