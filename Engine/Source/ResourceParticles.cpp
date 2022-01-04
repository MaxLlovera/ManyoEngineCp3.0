#include "ResourceParticles.h"

ResourceParticles::ResourceParticles(uint uid, std::string& assets, std::string& library) : Resource(uid, ResourceType::PARTICLES, assets, library)
{

}

ResourceParticles::~ResourceParticles()
{

}

void ResourceParticles::CleanUp()
{

}