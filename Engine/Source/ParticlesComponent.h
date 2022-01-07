#pragma once

#include "Component.h"
#include <vector>
#include "EmitterInstance.h"
#include "ResourceParticles.h"

class GameObject;

class ParticlesComponent : public Component
{
public:
	ParticlesComponent(GameObject* owner);
	~ParticlesComponent();
	
	void Save();
	void Load();
	void OnEditor() override;
	bool Update(float dt) override;
	void Reset();



public:
	std::vector<EmitterInstance> emitters;

	ResourceParticles* resourceParticles;

	Particles* partic;

	float particletime;
	int maxParticles;
};