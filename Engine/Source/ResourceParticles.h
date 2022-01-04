#pragma once

#include "Resource.h"
#include "ParticleEmitter.h"
#include <vector>

typedef unsigned int uint;


class ResourceParticles : public Resource
{
public:
	ResourceParticles(uint uid, std::string& assets, std::string& library);
	~ResourceParticles();

	void CleanUp();

public:
	std::vector<ParticleEmitter> emitters;

};