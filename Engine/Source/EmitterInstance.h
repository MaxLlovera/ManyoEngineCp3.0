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

	void Init(ParticleEmitter* emit);
	void UpdateModules();
	void DrawParticles();

	void NewParticle();
	void GenerateParticle();

public:
	std::vector<Particles> particles;
	ParticleEmitter* emitter;
	ParticlesComponent* owner;
	Particles* partic;

	int particles_count;
	int particles_spawning;
};