#include "Particle.h"

void Particle::Initalize(const Data& data)
{
	isActive = true;
	position = data.position;
	velocity = data.velocity;
	lifespan = data.lifespan;

}

void Particle::Update(float dt)
{

	position = position + (velocity * dt);
	if (lifespan != 0) lifespan = lifespan - dt;
}

void Particle::Draw(Renderer& renderer)
{
	if (lifespan > 0) {
		renderer.SetColor(rand() % 255,rand() % 255, rand() % 255, rand() % 255);
		renderer.DrawRect(position.x, position.y, 4.0f, 4.0f);
		//renderer.DrawPoint(position.x, position.y);
	}
	
}
