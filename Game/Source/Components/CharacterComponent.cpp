#include "CharacterComponent.h"
#include "Engine.h"

FACTORY_REGISTER(CharacterComponent)

void CharacterComponent::Initialize()
{
	owner->OnCollisionEnter = std::bind(&CharacterComponent::OnCollisionEnter, this, std::placeholders::_1);
}

void CharacterComponent::Update(float dt)
{
	bool onGround = (groundCount < 0);
	Vector2 direction{ 0,0 };
	if (owner->m_scene->m_engine->GetInput().GetKeyDown(SDL_SCANCODE_D)) direction.x =  1;
	if (owner->m_scene->m_engine->GetInput().GetKeyDown(SDL_SCANCODE_A)) direction.x = -1;
	physics->ApplyForce(direction * speed * 10);

	float modifier = (onGround) ? 1 : 0.5f;
	
	if (onGround && owner->m_scene->m_engine->GetInput().GetKeyDown(SDL_SCANCODE_SPACE))
	{
		physics->SetVelocity(Vector2{ 0,-500 });
	}

}

void CharacterComponent::OnCollisionEnter(Actor* actor)
{
	if (actor->tag == "ground") groundCount++;
}

void CharacterComponent::OnCollisionExit(Actor* actor)
{
	if (actor->tag == "ground") groundCount--;
}

void CharacterComponent::Read(const json_t& value)
{
	READ_DATA(value, speed);
}

void CharacterComponent::Write(json_t& value)
{

}
