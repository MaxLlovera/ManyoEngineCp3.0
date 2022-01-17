#include "Speed.h"

Speed::Speed() : ParticleEmitter(ParticleEmitterType::SPEED)
{
	type = ParticleEmitterType::SPEED;
	minVelocity = { 0.0f,0.0f,0.0f };
	maxVelocity = { 1.0f, 1.0f, 1.0f };
}

Speed::~Speed()
{
}

void Speed::Init(Particles& particle)
{
	LCG random;
	float randomVel_x = random.Float(minVelocity.x, maxVelocity.x);
	float randomVel_y = random.Float(minVelocity.y, maxVelocity.y);
	float randomVel_z = random.Float(minVelocity.z, maxVelocity.z);
	particle.speed = { randomVel_x, randomVel_y,randomVel_z };
}

void Speed::Update(Particles& particle, float dt)
{
}

