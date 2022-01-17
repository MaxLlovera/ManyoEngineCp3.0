#include "Particles.h"

Particles::Particles(GameObject* parent)
{
	lifeTime = 1.5f;
	rot = { 90.0f,0.0f,0.0f };
	speed = { 0.0f,0.0f,0.0f };
	position = { 0.0f,0.0f,0.0f };
	rotationQuat = Quat::FromEulerXYZ(rot.x, rot.y, rot.z);
	accel = { 0.0f,0.0f,0.0f };
	size = { 0.5f,0.5f,0.5f };
	color = { 0, 0, 0 };
	tex = nullptr;
	isActive = true;

	plane = app->scene->CreateGameObject(parent, true);
	plane->SetName("ParticleReference");
	plane->CreateComponent(ComponentType::MESH_RENDERER);
	plane->CreateComponent(ComponentType::BILLBOARD);
}

Particles::Particles(Particles* particleReference, GameObject* parent)
{
	lifeTime = particleReference->lifeTime;
	rot = particleReference->rot;
	speed = particleReference->speed;
	position = particleReference->position;
	accel = particleReference->accel;
	size = particleReference->size;
	color = particleReference->color;
	tex = particleReference->tex;
	isActive = particleReference->isActive;

	plane = app->scene->CreateGameObject(parent, true);
	plane->SetName("Particle");
	plane->CreateComponent(ComponentType::MESH_RENDERER);
	plane->CreateComponent(ComponentType::BILLBOARD);

	ResourceManager::GetInstance()->LoadResource(std::string("Assets/Resources/Sphere.fbx"), *plane);
}

bool Particles::OnLoad(JsonParsing& node)
{
	lifeTime = node.GetJsonNumber("Particle: LifeTime");
	accel = node.GetJson3Number(node, "Particle: Acceleration");
	size = node.GetJson3Number(node, "Particle: Size");
	speed = node.GetJson3Number(node, "Particle: Velocity");
	position = node.GetJson3Number(node, "Particle: Position");
	dir = node.GetJson3Number(node, "Particle: Direction");;
	isActive = node.GetJsonBool("Particle: Is Active");
	return true;
}

bool Particles::OnSave(JsonParsing& node, JSON_Array* array)
{
	JsonParsing file = JsonParsing();
	file.SetNewJsonNumber(file.ValueToObject(file.GetRootValue()), "Particle: LifeTime", lifeTime);
	file.SetNewJson3Number(file, "Particle: Acceleration", accel);
	file.SetNewJson3Number(file, "Particle: Size", size);
	file.SetNewJson3Number(file, "Particle: Velocity", speed);
	file.SetNewJson3Number(file, "Particle: Position", position);
	file.SetNewJson3Number(file, "Particle: Direction", dir);
	file.SetNewJsonBool(file.ValueToObject(file.GetRootValue()), "Particle: Is Active", isActive);
	node.SetValueToArray(array, file.GetRootValue());
	return true;
}