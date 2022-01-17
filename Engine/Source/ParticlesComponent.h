#pragma once
#include "Particles.h"
#include "Globals.h"
#include "Component.h"
#include "GameTimer.h"
#include "Color.h"

#include "MathGeoLib/src/MathGeoLib.h"
#include <vector>

class CameraComponent;
class TransformComponent;
class EmitterInstance;

class ParticlesComponent : public Component {

public:
	ParticlesComponent(GameObject* own, TransformComponent* trans, uint numParticles = 1);
	~ParticlesComponent();

	void SetEmitter(EmitterInstance* emitter);
	bool Update(float dt) override;
	void OnEditor() override;
public:
	bool looping = false;
	float maxDuration = 0.0f;

protected:
	int maxParticlesEditor = 200;
	float lifetimeEditor = 20.0f;
	float speedEditor = 5.0f;
	float sizeEditor = 5.0f;
	Color colorEditor = white;
	std::vector<EmitterInstance*> emitters;
	bool isActive;
	GameTimer timer;
	TransformComponent* transform;
};
