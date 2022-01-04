#pragma once

#include "Component.h"
#include <vector>
#include "EmitterInstance.h"

class GameObject;

class ParticlesComponent : public Component
{
public:
	ParticlesComponent(GameObject* own);
	~ParticlesComponent();

	void Save();
	void Load();

	void Update();
	void Reset();



public:
	std::vector<EmitterInstance> emitters;
};