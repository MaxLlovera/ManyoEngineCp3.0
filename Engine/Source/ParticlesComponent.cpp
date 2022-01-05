#include "ParticlesComponent.h"



ParticlesComponent::ParticlesComponent(GameObject* own)
{
	type = ComponentType::PARTICLE;
	owner = own;

	resourceParticles = nullptr;
	particletime = 0;
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

void ParticlesComponent::Update()
{
	for (size_t i = 0; i < emitters.size(); i++)
	{
		emitters[i].UpdateModules();
	}
}

void ParticlesComponent::Reset()
{

}

