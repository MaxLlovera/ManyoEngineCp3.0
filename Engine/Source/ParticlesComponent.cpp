#include "ParticlesComponent.h"



ParticlesComponent::ParticlesComponent(GameObject* own)
{
	type = ComponentType::PARTICLE;
	owner = own;
	
	partic = new Particles();
	resourceParticles = nullptr;
	partic->size = 1.f;
	maxParticles = 150;
	partic->lifetime = 5.f;
	partic->velocity = 1.f;
	partic->color = white;

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
		if (ImGui::SliderFloat("Lifetime", &partic->lifetime, 0.0f, 15.0f))
		{
			
		}
		if (ImGui::SliderInt("Max Particles", &maxParticles, 0.0f, 150.0f))
		{

		}
		//if (ImGui::SliderInt("EmisionRate", &maxParticles, 0.0f, 150.0f))
		//{

		//}
		if (ImGui::SliderFloat("Angle", &partic->angle, 0.0f, 150.0f))
		{

		}
		if (ImGui::SliderFloat("Speed", &partic->velocity, 0.0f, 150.0f))
		{

		}
		if (ImGui::SliderFloat("Size", &partic->size, 0.0f, 150.0f))
		{

		}
		ImGui::Text("COLOR");
		if (ImGui::ColorPicker3("Preview", &partic->color))
		{

		}

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

