#include "EmitterInstance.h"
#include "ParticleEmitter.h"
EmitterInstance::EmitterInstance()
{
	particles_count = 0;
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

}

void EmitterInstance::DrawParticles()
{
}

void EmitterInstance::NewParticle()
{
	Particles* newParticle = new Particles(partic);
}