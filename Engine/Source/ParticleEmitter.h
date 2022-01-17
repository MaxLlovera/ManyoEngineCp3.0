#pragma once
#include "Particles.h"

class ParticleEmitter
{
public:
	ParticleEmitter();
	~ParticleEmitter();

	void Init(Particles& particle);
	void Update(Particles& particle, float dt);


public:
	float3 minVelocity, maxVelocity;
	LCG random;
	bool del;
};