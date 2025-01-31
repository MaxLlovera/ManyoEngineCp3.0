#pragma once
#include "Particles.h"
#include "GameObject.h"
#include "Resource.h"
#include "Texture.h"
#include "Application.h"
#include "ModuleScene.h"
#include "ParticleEmitter.h"
#include "MathGeoLib/src/Geometry/Frustum.h"
#include "MathGeoLib/src/Algorithm/Random/LCG.h"
#include <string>
#include "ParticleEmitter.h"

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

	void CreateParticleEffect(ParticleEmitterType type);
	ParticleEmitter* GetParticleEffect(ParticleEmitterType type);
	bool isEffectActive(ParticleEmitterType type);

public:

	int maxParticles;
	float particSecond;
	bool isActive;
	bool toDelete;

	std::vector<Particles*> particlesBuff;
	std::vector<ParticleEmitter*> effects;
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
