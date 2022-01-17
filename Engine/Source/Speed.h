#pragma once
#include "ParticleEmitter.h"
#include "MathGeoLib/src/Algorithm/Random/LCG.h"

class Speed : ParticleEmitter
{
public:
	Speed();
	~Speed();

	void Init(Particles& particle) override;
	void Update(Particles& particle, float dt) override;

public:

	float3 minVelocity, maxVelocity;
	LCG random;
};