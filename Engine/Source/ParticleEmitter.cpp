#include "ParticleEmitter.h"

ParticleEmitter::ParticleEmitter(ParticleEmitterType type)
{
	this->type = type;
	del = false;
}

ParticleEmitter::~ParticleEmitter()
{
}

void ParticleEmitter::Init(Particles& particle)
{
}

void ParticleEmitter::Update(Particles& particle, float dt)
{
}

