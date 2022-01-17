#include "ParticlesComponent.h"
#include "Globals.h"
#include "EmitterInstance.h"
#include "CameraComponent.h"
#include "TransformComponent.h"
#include "GameObject.h"

#include <cassert>
#include <GL/glew.h>
#include "Dialogs.h"

ParticlesComponent::ParticlesComponent(GameObject* own, TransformComponent* trans, uint numParticles)
{
    type = ComponentType::PARTICLE_SYSTEM;
    transform = trans;
    isActive = true;
    
}

ParticlesComponent::~ParticlesComponent()
{
}

void ParticlesComponent::SetEmitter(EmitterInstance* emitter)
{
    emitters.push_back(emitter);
}


bool ParticlesComponent::Update(float dt)
{
    if (isActive && (((float)timer.GetTime())/1000.0f < maxDuration || looping == true))
    {
        for (int i = 0; i < emitters.size(); i++) {
            emitters[i]->Update(dt);
        }
    }
    
    return true;
}

void ParticlesComponent::OnEditor()
{
	ImGui::PushID(this);
	if (ImGui::CollapsingHeader("Particle System"))
	{
		if (ImGui::SliderFloat("Lifetime", &lifetimeEditor, 0.0f, 15.0f))
		{
			
		}
		if (ImGui::SliderInt("Max Particles", &maxParticlesEditor, 0.0f, 150.0f))
		{

		}
		//if (ImGui::SliderInt("EmisionRate", &maxParticles, 0.0f, 150.0f))
		//{

		//}
		/*if (ImGui::SliderFloat("Angle", &angle, 0.0f, 150.0f))
		{

		}*/
		if (ImGui::SliderFloat("Speed", &speedEditor, 0.0f, 150.0f))
		{

		}
		if (ImGui::SliderFloat("Size", &sizeEditor, 0.0f, 150.0f))
		{

		}
		ImGui::Text("COLOR");
		if (ImGui::ColorPicker3("Preview", &colorEditor))
		{

		}
	}
	ImGui::PopID();
}