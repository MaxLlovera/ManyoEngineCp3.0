#pragma once


#include <vector>
#include "Texture.h"
#include "ModuleParticles.h"

class ParticleEmitter
{
public:
	ParticleEmitter();
	~ParticleEmitter();

	void Save();
	void Load();
	//ModuleParticles* AddModule(type);

public:
	std::string name;
	Texture* particlesTexture;
	std::vector<ModuleParticles*> modules;
	uint max_particles;
};