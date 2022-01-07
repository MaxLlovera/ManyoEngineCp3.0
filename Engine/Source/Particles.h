#pragma once

#include "Component.h"
#include "BillboardComponent.h"

class Particles {
public:

	Particles();
	Particles(Particles* partic);
	~Particles();


public:
	float3 position;
	Quat worldRotation;
	float lifetime;
	float velocity;
	//float3 speed;
	float size;
	float angle;
	float weight;
	float life;
	unsigned char r, g, b, a;
	BillboardComponent* billboardComponent;
	float3 direction;

};