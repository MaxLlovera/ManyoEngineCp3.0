#include "ModuleParticles.h"
#include "glew/include/GL/glew.h"

ModuleParticles::ModuleParticles()
{
}

ModuleParticles::~ModuleParticles()
{
}

void ModuleParticles::Spawn(EmitterInstance* emitterInstance)
{
	//if (particles_count < emitterInstance->owner->maxParticles) {
	//	//Create new particles until the vector is full
	//	NewParticle(emitterInstance);
	//}



	//else if (GetFirstUnusedParticle() != -1 && activeParticles < emitterInstance->owner->maxParticles)
	//{
	//	uint index = GetFirstUnusedParticle();
	//	particles_vector[index].active = true; activeParticles++; //Reactivate particle        
	//	particleReference->position = emitterInstance->owner->owner->transform->position; //Get position from C_Transform

	//	//We update values from Particle Reference
	//	particles_vector[index].position = particleReference->position;
	//	particles_vector[index].lifetime = particleReference->lifetime;
	//	particles_vector[index].direction = particleReference->direction + SetRandomDirection();
	//	particles_vector[index].size = particleReference->size;
	//	particles_vector[index].speed = particleReference->speed;
	//	particles_vector[index].color = particleReference->color;
	//}
}

void ModuleParticles::Update(EmitterInstance* emitterInstance)
{

}

void ModuleParticles::Save()
{
}

void ModuleParticles::Load()
{
}

void ModuleParticles::Draw()
{
	for (size_t i = 0; i < particles.size(); i++)
	{
		//if (particles[i].active)
		//{
		particles[i].position += particles[i].velocity * particles[i].direction;
		glColor4f(0.2f, 0.2f, 1.0f, 1.0f);
		glPointSize(20);
		glBegin(GL_POINTS);
		glVertex3f(particles[i].position.x, particles[i].position.y, particles[i].position.z);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		glEnd();
		/*particles[i].billboardComponent->transform->position = particles[i].position;
		particles[i].billboardComponent->transform->scale = float3(particles[i].size);
		particles[i].billboardComponent->DrawBilboard(particles[i].color);
*/
		//}
	}

}




void ModuleParticles::NewParticle(EmitterInstance* emitterInstance)
{
	Particles* newParticle = new Particles(partic);

	//newParticle->billboardComponent = (BillboardComponent*)emitterInstance->owner->owner->CreateComponent(Component::Type::Billboard);

	//if (newParticle != nullptr)
	//{
	//	particles_vector.push_back(newParticle);
	//	existing_particles++;
	//	activeParticles++;
	//	//particles_vector[particles_vector.size()-1].color = owner->GetRandomColor(owner->color);
	//	particles_vector[particles_vector.size() - 1].direction = particleReference->direction + SetRandomDirection();
	//}
}

void ModuleParticles::GenerateParticle()
{
	//particles_spawning = 10;

	//for (size_t i = 0; i < particles_spawning; ++i)
	//{
	//	if (particles_count < particles_spawning)
	//	{
	//		NewParticle();
	//	}
	//}
}