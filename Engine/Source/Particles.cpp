#include "Particles.h"

Particles::Particles(uint uid, std::string& assets, std::string& library) : Resource(uid, ResourceType::PARTICLES, assets, library)
{

}

Particles::~Particles()
{

}

void Particles::CleanUp()
{

}