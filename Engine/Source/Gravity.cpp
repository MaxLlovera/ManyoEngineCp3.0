#include "Gravity.h"

Gravity::Gravity() : ParticleEmitter(ParticleEmitterType::GRAVITY)
{
	type = ParticleEmitterType::GRAVITY;
	gravity = -9.81f;
	accele = float3(0.0f, 0.0f, 0.0f);
}

Gravity::~Gravity()
{
}

void Gravity::Update(Particles& particle, float dt)
{
	particle.accel = accele;
	if (hasGravity)
	{
		particle.accel.y += gravity;
	}
}
