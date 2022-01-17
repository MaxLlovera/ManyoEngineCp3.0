#include "EmitterInstance.h"
#include "ResourceManager.h"
#include "Mesh.h"
#include "TextureImporter.h"
#include "Speed.h"
#include "Gravity.h"

EmitterInstance::EmitterInstance(GameObject* owner)
{
	own = owner;
	particleReference = new Particles(own);
	particlesBuff.resize(0);
	effects.resize(3);
	maxParticles = 200;
	particSecond = 50;
	isActive = true;
	minLifeTime = 0.7f;
	maxLifeTime = 1.7f;
	timer = 1.0f/particSecond;
	currTimer = timer;
	showTexMenu = false;
}

EmitterInstance::~EmitterInstance()
{
}

void EmitterInstance::Emit(float dt)
{
	currTimer -= dt;
	if (currTimer <= 0.0f) {
		
		for (int i = 0; i < particlesBuff.size(); i++) {
			TransformComponent* transform =	(TransformComponent*)own->GetComponent(ComponentType::TRANSFORM);
			if (transform != nullptr)
			{
				if (particlesBuff[i]->isActive == false)
				{
					particlesBuff[i]->isActive = true;
					particlesBuff[i]->lifeTime = particleReference->lifeTime;
					particlesBuff[i]->position = transform->position;
					particlesBuff[i]->rot = particleReference->rot;
					particlesBuff[i]->size = particleReference->size;
					particlesBuff[i]->color = particleReference->color;

					for (int j = 0; j < effects.size(); j++)
					{
						if (effects[j] != nullptr)
						{
							effects[j]->Init(*particlesBuff[i]);
						}
					}

					return;
				}
			}
		}

		if (particlesBuff.size() < maxParticles) {
			Particles* particle = new Particles(particleReference, own);
			particlesBuff.push_back(particle);
		}
		currTimer = timer;
	}
}

void EmitterInstance::CreateParticleEffect(ParticleEmitterType type)
{
	ParticleEmitter* emitter = nullptr;

	switch (type)
	{
	case ParticleEmitterType::NONE:
		effects[(int)ParticleEmitterType::NONE] = emitter;
		break;

	case ParticleEmitterType::SPEED:
		emitter = (ParticleEmitter*)new Speed();
		effects[(int)ParticleEmitterType::SPEED] = emitter;
		break;
	case ParticleEmitterType::GRAVITY:
		emitter = (ParticleEmitter*)new Gravity();
		effects[(int)ParticleEmitterType::GRAVITY] = emitter;
		break;
	default:
		break;
	}
}

void EmitterInstance::Render()
{
	for (int i = 0; i < particlesBuff.size(); i++) {

		if (particlesBuff[i]->isActive == true)
		{
			TransformComponent* planeTransform = (TransformComponent*)particlesBuff[i]->plane->GetComponent(ComponentType::TRANSFORM);
			if (planeTransform != nullptr)
			{
				planeTransform->SetTransform(particlesBuff[i]->position, Quat::FromEulerXYZ(particlesBuff[i]->rot.x, particlesBuff[i]->rot.y, particlesBuff[i]->rot.z), particlesBuff[i]->size);
			}

			MeshComponent* planeMesh = (MeshComponent*)particlesBuff[i]->plane->GetComponent(ComponentType::MESH_RENDERER);
			if (planeMesh != nullptr)
			{
				planeMesh->colorNormal = particlesBuff[i]->color;
			}
		}
	}
}

void EmitterInstance::UpdateParticle(float dt)
{
	for (int i = 0; i < particlesBuff.size(); i++) {
		
		if (particlesBuff[i]->isActive == true)
		{
			for (int j = 0; j < effects.size(); j++)
			{
				if (effects[j] != nullptr && isEffectActive(effects[j]->type))
				{
					effects[j]->Update(*particlesBuff[i], dt);
				}
			}

			particlesBuff[i]->lifeTime -= dt;
			particlesBuff[i]->speed += particlesBuff[i]->accel * dt;// * dt;
			particlesBuff[i]->position += particlesBuff[i]->speed;
		}

		if (particlesBuff[i]->lifeTime <= 0)
			particlesBuff[i]->isActive = false;
	}


}

void EmitterInstance::Update(float dt)
{
	UpdateParticle(dt);
	Render();
	Emit(dt);
}

void EmitterInstance::OnEditor(int emitterIndex)
{

}

void EmitterInstance::ParticSecond(float particSec)
{
	particSecond = particSec;
	timer = 1.0f / particSecond;
}

bool EmitterInstance::isEffectActive(ParticleEmitterType type)
{
	for (int i = 0; i < effects.size(); ++i)
	{
		if (effects[i] != nullptr && effects[i]->type == type)
		{
			return true;
		}
	}
	return false;
}

ParticleEmitter* EmitterInstance::GetParticleEffect(ParticleEmitterType type)
{
	for (int i = 0; i < effects.size(); i++)
	{
		if (effects[i] != nullptr && effects[i]->type == type)
		{
			return effects[i];
		}
	}
}

