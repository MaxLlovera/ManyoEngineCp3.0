#pragma once

#include <vector>
#include "Particles.h"


class ParticlesComponent;
class ParticleEmitter;

class EmitterInstance
{
public:
	EmitterInstance(ParticleEmitter* emitterReference);
	~EmitterInstance();

	void Init();
	void UpdateModules();
	void DrawParticles();




public:

	ParticleEmitter* emitter;
	ParticlesComponent* owner;
	Particles* partic;

};