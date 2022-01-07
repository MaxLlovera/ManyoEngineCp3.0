#pragma once

#include <vector>
#include "Particles.h"


class EmitterInstance;

enum class TypeParticle {
	NONE,
};

class ModuleParticles {

public:
	ModuleParticles();
	~ModuleParticles();

	void Spawn(EmitterInstance* emitterInstance);
	void Update(EmitterInstance* emitterInstance);
	void Save();
	void Load();
	void Draw();

	void NewParticle(EmitterInstance* emitterInstance);
	void GenerateParticle();


public:
	std::vector<Particles> particles;
	
	Particles* partic;

	int particles_count;
	int particles_spawning;
};