#pragma once

#include <vector>
#include "Particles.h"

class ParticlesComponent;
class ParticleEmitter;

class EmitterInstance
{
public:
	EmitterInstance();
	~EmitterInstance();

	void Init();
	void UpdateModules();
	void DrawParticles();

public:

	std::vector<Particles> particles;
	ParticleEmitter* emitter;
	ParticlesComponent* owner;
};