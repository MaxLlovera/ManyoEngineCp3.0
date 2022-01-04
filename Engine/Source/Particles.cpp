#include "Particles.h"

Particles::Particles()
{
}

Particles::Particles(Particles* partic)
{
	position = partic->position;
	worldRotation = partic->worldRotation;
	lifetime = partic->lifetime;
	velocity = partic->velocity;
}

Particles::~Particles()
{
}