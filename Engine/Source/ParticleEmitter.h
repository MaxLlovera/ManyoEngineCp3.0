#pragma once
#include "Particles.h"

enum class ParticleEmitterType : int
{
	NONE = -1,
	SPEED,
	GRAVITY,
};

class ParticleEmitter
{
public:
	ParticleEmitter(ParticleEmitterType type);
	~ParticleEmitter();

	virtual void Init(Particles& particle);
	virtual void Update(Particles& particle, float dt);


public:

	ParticleEmitterType type;
	bool del;
};