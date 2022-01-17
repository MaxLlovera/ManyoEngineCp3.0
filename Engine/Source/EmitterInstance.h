#pragma once
#include "Particles.h"
#include "GameObject.h"
#include "Resource.h"
#include "Texture.h"
#include "Application.h"
#include "ModuleScene.h"
#include "MathGeoLib/src/Geometry/Frustum.h"
#include "MathGeoLib/src/Algorithm/Random/LCG.h"
#include <string>

class EmitterInstance {
public:

	EmitterInstance(GameObject* owner);
	~EmitterInstance();

	virtual void Emit(float dt);
	void Render();
	virtual void UpdateParticle(float dt);
	virtual void Update(float dt);

	void OnEditor(int emitterIndex);
	void ParticSecond(float particSec);

public:

	int maxParticles;
	float particSecond;
	bool isActive;
	bool toDelete;

	std::vector<Particles*> particlesBuff;
	Particles* particleReference;
	GameObject* own;

	float minLifeTime;
	float maxLifeTime;

	float timer;
	float currTimer;

	char charsOfName[50];
	bool showTexMenu;
	LCG random;
};