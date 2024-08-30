#pragma once


// **Core**
#include "Core/E_Timer.h"
#include "Core/EAssert.h"
#include "Core/EFile.h"
#include "Core/Json.h"
#include "Core/Singleton.h"
#include "Core/Factory.h"
#include "Core/EString.h"

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
#include "Math/Rect.h"

//**EventSystem*
#include "Event/EventSystem.h"

// **Physics**  
#include "Physics/Physics.h"
#include "Physics/RigidBody.h"

// **Framework** 
#include "Framework/Actor.h"
#include "Framework/Scene.h"
#include "Framework/Game.h"

// **Recources**
#include "Recources/Resource.h"
#include "Recources/RecourceManager.h"

// **Components**
#include "Components/TextureComponent.h"
#include "Components/EnginePhysicsComponent.h"
#include "Components/TextCompontent.h"
#include "Components/TextureAnimationComponent.h"
#include "Components/Box2DPhysicsComponent.h"


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

	Physics& GetPhysics() { return *m_physics; }

	


private:

	bool quit{ false };

	std::unique_ptr<Renderer> m_renderer;
	std::unique_ptr<Input> m_input;
	std::unique_ptr<Audio> m_audio;
	std::unique_ptr<Time> m_time;
	std::unique_ptr<ParticleSystem> m_particleSytem;
	std::unique_ptr<Physics> m_physics;
	std::unique_ptr<TextureAnimationComponent> m_textureanimation;
};



