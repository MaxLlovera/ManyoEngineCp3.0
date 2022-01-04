#pragma once



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
};