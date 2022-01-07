#include "ParticlesComponent.h"



ParticlesComponent::ParticlesComponent(GameObject* own)
{
	type = ComponentType::PARTICLE;
	owner = own;
	
	partic = new Particles();
	resourceParticles = nullptr;
	particletime = 0;
	partic->size = 1.f;
	maxParticles = 150;

}
ParticlesComponent::~ParticlesComponent()
{
}


void ParticlesComponent::Save()
{

}

void ParticlesComponent::Load()
{

}

void ParticlesComponent::OnEditor()
{
	ImGui::PushID(this);
	if (ImGui::CollapsingHeader("Particle System"))
	{
		ImGui::Text("Particle System");
	}
	ImGui::PopID();
}

bool ParticlesComponent::Update(float dt)
{
	for (size_t i = 0; i < emitters.size(); i++)
	{
		emitters[i].UpdateModules();
	}
	return true;
}

void ParticlesComponent::Reset()
{

}

