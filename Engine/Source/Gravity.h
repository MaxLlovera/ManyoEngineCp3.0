#pragma once
#pragma once
#include "ParticleEmitter.h"

class Gravity : ParticleEmitter
{
public:
	Gravity();
	~Gravity();

	void Update(Particles& particle, float dt) override;


public:

	bool hasGravity;
	float gravity;
	float3 accele;
};