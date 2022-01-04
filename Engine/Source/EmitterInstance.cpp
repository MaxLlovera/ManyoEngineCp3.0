#include "EmitterInstance.h"
#include "ParticleEmitter.h"
EmitterInstance::EmitterInstance()
{
	particles_count = 0;
	particles_spawning = 0;

	partic = new Particles();
	partic->position = { 0,0,0 };
	partic->lifetime = 100;
	partic->worldRotation = { 0,0,0,1 };
}

EmitterInstance::~EmitterInstance()
{

}

void EmitterInstance::Init(ParticleEmitter* emit)
{
	this->emitter = emit;
	if (this->emitter != nullptr)
	{
		particles.resize(emitter->max_particles);
	}
	else
	{
		particles.resize(0);
	}
}

void EmitterInstance::UpdateModules()
{
	for (uint i = 0; i < emitter->modules.size(); ++i)
	{
		emitter->modules[i]->Update(this);//Time::deltaTime
	}
	GenerateParticle();
}

void EmitterInstance::DrawParticles()
{
}

void EmitterInstance::NewParticle()
{
	Particles* newParticle = new Particles(partic);

	if (newParticle != nullptr)
	{
		particles_count++;
	}
}

void EmitterInstance::GenerateParticle()
{
	particles_spawning = 10;

	for (size_t i = 0; i < particles_spawning; ++i)
	{
		if (particles_count < particles_spawning)
		{
			NewParticle();
		}
	}
}