#include "EmitterInstance.h"
#include "ParticleEmitter.h"

EmitterInstance::EmitterInstance(ParticleEmitter* emitterReference)
{
	
	this->emitter = emitterReference;
	
}

EmitterInstance::~EmitterInstance()
{

}

void EmitterInstance::Init()
{
	//this->emitter = emit;
	if (this->emitter != nullptr)
	{
		//particles.resize(emitter->max_particles);
	}
	else
	{
		//particles.resize(0);
	}
}

void EmitterInstance::UpdateModules()
{
	for (uint i = 0; i < emitter->modules.size(); ++i)
	{
		emitter->modules[i]->Update(this);//Time::deltaTime
	}
	//GenerateParticle();
}

void EmitterInstance::DrawParticles()
{
	for (uint i = 0; i < emitter->modules.size(); ++i)
	{
		emitter->modules[i]->Draw();
	}
}