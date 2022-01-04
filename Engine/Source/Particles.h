#pragma once

#include "Component.h"

class Particles {
public:

	Particles();
	Particles(Particles* partic);
	~Particles();


public:
	float3 position;
	Quat worldRotation;
	float lifetime;
	float4 velocity;
};