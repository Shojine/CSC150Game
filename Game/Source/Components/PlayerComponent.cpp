#include "PlayerComponent.h"
#include "Engine.h"

FACTORY_REGISTER(PlayerComponent)

void PlayerComponent::Initialize()
{
	owner->OnCollisionEnter = std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1);
}

void PlayerComponent::Update(float dt)
{
	Vector2 direction{ 0,0 };

	if (owner->m_scene->m_engine->GetInput().GetKeyDown(SDL_SCANCODE_D)) direction.x =  1;
	if (owner->m_scene->m_engine->GetInput().GetKeyDown(SDL_SCANCODE_A)) direction.x = -1;
	if (owner->m_scene->m_engine->GetInput().GetKeyDown(SDL_SCANCODE_W)) direction.y = -1;
	if (owner->m_scene->m_engine->GetInput().GetKeyDown(SDL_SCANCODE_S)) direction.y =  1;


	owner->GetComponent<PhysicsComponent>()->ApplyForce(direction * speed);
	
	if (owner->m_scene->m_engine->GetInput().GetKeyDown(SDL_SCANCODE_SPACE))
	{
		auto rocket = Factory::Instance().Create<Actor>("rocket");
		owner->m_scene->AddActor(std::move(rocket),true);

		rocket->m_transform.position = owner->m_transform.position;
		rocket->m_transform.rotation = owner->m_transform.rotation;

	}

}

void PlayerComponent::OnCollisionEnter(Actor* actor)
{
	std::cout << "player hit" << std::endl;

	EVENT_NOTIFY(PlayerDead);
	
	
}

void PlayerComponent::Read(const json_t& value)
{
	READ_DATA(value, speed);
}

void PlayerComponent::Write(json_t& value)
{

}
